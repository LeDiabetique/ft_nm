#include "../includes/ft_nm.h"

void handle_elf(void *sections_v, void *header_v, t_nm *nm, int is_64)
{
    int j = -1;
    void *symsection = NULL;
    char *strtab = NULL;
    int bits = is_64 ? 16 : 8;

    if ((j = get_symbol_section(header_v, sections_v, is_64)) >= 0) {
        symsection = get_section(sections_v, j, is_64);
        void *linked_section = get_linked_section(sections_v, symsection, is_64);
        strtab = (char *)(nm->ptr + get_section_offset(linked_section, is_64));

    } 
    else {
        ft_error(nm->filename, 3);
    }
    if (strtab && symsection) {
        void *symtab = (nm->ptr + get_section_offset(symsection, is_64));
        int sym_size = get_section_size(symsection, is_64) / get_section_entsize(symsection, is_64);
        t_symbol *sym_array = malloc(sym_size * sizeof(t_symbol));
        if (!sym_array)
            return ft_error("Error: Malloc failed\n", 0);
        int i_sym = 0;
        for (int i = 0; i < sym_size; i++) {
            void *symbol = get_symbol(symtab, i, is_64);
            if (!strtab[get_symbol_name(symbol, is_64)])
            {
                continue;
            }
            unsigned char type = get_st_type(symbol, is_64);
            if (type == STT_FUNC || type == STT_OBJECT || get_symbol_shndx(symbol, is_64) == SHN_UNDEF || type != STT_FILE) {
                unsigned char letter = get_letter(type, symbol, get_section(sections_v, get_symbol_shndx(symbol, is_64), is_64), is_64);
                char *addr = get_addr_formatted(get_symbol_value(symbol, is_64), bits, letter);
                char *name = &strtab[get_symbol_name(symbol, is_64)];
                sym_array[i_sym].addr = addr;
                sym_array[i_sym].type = letter;
                sym_array[i_sym].name = name;
                i_sym++;
            }
        }
        bubble_sort(sym_array, i_sym);
        for (int i = 0; i < i_sym; i++) {
            ft_printf("%s %c %s\n", sym_array[i].addr, sym_array[i].type, sym_array[i].name);
            free(sym_array[i].addr);
        }
        free(sym_array);
    }
}