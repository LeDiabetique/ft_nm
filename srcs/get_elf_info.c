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

void *get_linked_section(void *sections_v, void *symsection, int is_64)
{
    unsigned int sh_link;
    if (is_64) {
        Elf64_Shdr *symsec = (Elf64_Shdr *)symsection;
        sh_link = symsec->sh_link;
        return (void *)((Elf64_Shdr *)sections_v + sh_link);
    } else {
        Elf32_Shdr *symsec = (Elf32_Shdr *)symsection;
        sh_link = symsec->sh_link;
        return (void *)((Elf32_Shdr *)sections_v + sh_link);
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

