#include "../includes/ft_nm.h"

int get_shnum(void *header_v, int is_64)
{
    if (is_64) {
        Elf64_Ehdr *header = (Elf64_Ehdr *)header_v;
        return header->e_shnum;
    } else {
        Elf32_Ehdr *header = (Elf32_Ehdr *)header_v;
        return header->e_shnum;
    }
}

int get_sh_type(void *sections_v, int i, int is_64) {
    if (is_64) {
        Elf64_Shdr *sections = (Elf64_Shdr *)sections_v;
        return sections[i].sh_type;
    } else {
        Elf32_Shdr *sections = (Elf32_Shdr *)sections_v;
        return sections[i].sh_type;
    }
}

int get_st_type(void *symbol_v, int is_64)
{
    if (is_64) {
        Elf64_Sym *symbol = (Elf64_Sym *)symbol_v;
        return ELF64_ST_TYPE(symbol->st_info);
    } else {
        Elf32_Sym *symbol = (Elf32_Sym *)symbol_v;
        return ELF32_ST_TYPE(symbol->st_info);
    }
}

int get_symbol_section(void *header_v, void *sections_v, int is_64) {
    int shnum = get_shnum(header_v, is_64);

    for (int i = 0; i < shnum; i++) {
        if (get_sh_type(sections_v, i, is_64) == SHT_SYMTAB) {
            return i;
        }
    }
    return -1;
}

unsigned char get_symbol_bind(void* symbol, int is_64) {
    if (is_64) {
        return ELF64_ST_BIND(((Elf64_Sym*)symbol)->st_info);
    } else {
        return ELF32_ST_BIND(((Elf32_Sym*)symbol)->st_info);
    }
}

int get_section_flags(void* section, int is_64) {
    if (is_64) {
        return ((Elf64_Shdr*)section)->sh_flags;
    } else {
        return ((Elf32_Shdr*)section)->sh_flags;
    }
}

int get_section_type(void* section, int is_64) {
    if (is_64) {
        return ((Elf64_Shdr*)section)->sh_type;
    } else {
        return ((Elf32_Shdr*)section)->sh_type;
    }
}

unsigned short get_symbol_shndx(void* symbol, int is_64) {
    if (is_64) {
        return ((Elf64_Sym*)symbol)->st_shndx;
    } else {
        return ((Elf32_Sym*)symbol)->st_shndx;
    }
}

int get_symbol_value(void* symbol, int is_64) {
    if (is_64) {
        return ((Elf64_Sym*)symbol)->st_value;
    } else {
        return ((Elf32_Sym*)symbol)->st_value;
    }
}

int get_section_offset(void* section, int is_64) {
    if (is_64) {
        return ((Elf64_Shdr*)section)->sh_offset;
    } else {
        return ((Elf32_Shdr*)section)->sh_offset;
    }
}

int get_section_size(void* section, int is_64) {
    if (is_64) {
        return ((Elf64_Shdr*)section)->sh_size;
    } else {
        return ((Elf32_Shdr*)section)->sh_size;
    }
}

int get_section_entsize(void* section, int is_64) {
    if (is_64) {
        return ((Elf64_Shdr*)section)->sh_entsize;
    } else {
        return ((Elf32_Shdr*)section)->sh_entsize;
    }
}

void *get_section(void *sections_v, int i, int is_64) {
    if (is_64) {
        Elf64_Shdr *sections = (Elf64_Shdr *)sections_v;
        return (void *)(&sections[i]);
    } else {
        Elf32_Shdr *sections = (Elf32_Shdr *)sections_v;
        return (void *)(&sections[i]);    }
}

void *get_symbol(void *symtab, int i, int is_64) {
    if (is_64) {
        Elf64_Sym *sym = (Elf64_Sym *)symtab;
        return (void *)(&sym[i]);
    } else {
        Elf32_Sym *sym = (Elf32_Sym *)symtab;

        return (void *)(&sym[i]);
    }
}

int get_symbol_name(void *symbol, int is_64) {
    if (is_64) {
        return ((Elf64_Sym *)symbol)->st_name;
    } else {
        return ((Elf32_Sym *)symbol)->st_name;
    }
}

void handle_32_bits(Elf32_Shdr *sections, Elf32_Ehdr *header, t_nm *nm)
{
    int is_64 = 0;
    Elf32_Shdr *symsection = NULL;
	char *strtab = NULL;
	int j = -1;
	if ((j = get_symbol_section((void *)header, (void *)sections, is_64)) >= 0)
	{
		symsection = &sections[j];
		strtab = (char *)(nm->ptr + sections[symsection->sh_link].sh_offset);
	}
	else
		ft_error(nm->filename, 3);
	if (strtab && symsection)
	{
		Elf32_Sym *symtab = (Elf32_Sym *)(nm->ptr + symsection->sh_offset);
		int sym_size = symsection->sh_size / symsection->sh_entsize;
		t_symbol *sym_array = malloc(sym_size * sizeof(t_symbol));
		if (!sym_array)
			return ft_error("Error: Malloc failed\n", 0);
		int i_sym = 0;
		for(int i = 0; i < sym_size; i++)
		{
			Elf32_Sym *symbol = &symtab[i];
			if (!strtab[symbol->st_name])
				continue;
			unsigned char type = get_st_type((void *)symbol, is_64);
			if (type == STT_FUNC || type == STT_OBJECT || symbol->st_shndx == SHN_UNDEF || type != STT_FILE)
			{
				unsigned char letter = get_letter(type, (void *)symbol, (void *)&sections[symbol->st_shndx], is_64); //modif cast
				char *addr = get_addr_formatted(symbol->st_value, 8, letter);
				char *name = &strtab[symbol->st_name];
				sym_array[i_sym].addr = addr;
				sym_array[i_sym].type = letter;
				sym_array[i_sym].name = name;
				i_sym++;
			}
		}
		bubble_sort(sym_array, i_sym);
		for (int i = 0; i < i_sym; i++)
		{
			ft_printf("%s %c %s\n", sym_array[i].addr, sym_array[i].type, sym_array[i].name);
			free(sym_array[i].addr);
		}
		free(sym_array);
	}
}
