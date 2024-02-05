#include "../includes/ft_nm.h"
// int	get_symbol_section(void *header_v, void *sections_v, int is_64)
// {
	
// 	if (is_64 == 1)
// 	{
// 		Elf64_Ehdr *header = (Elf64_Ehdr *)header_v;
// 		Elf64_Shdr *sections = (Elf64_Shdr *)sections_v;
// 		for (int i = 0; i < header->e_shnum; i++)
// 			if (sections[i].sh_type == SHT_SYMTAB)
// 				return (i);
// 	}
// 	else
// 	{
// 		Elf32_Ehdr *header = (Elf32_Ehdr *)header_v;
// 		Elf32_Shdr *sections = (Elf32_Shdr *)sections_v;
// 		for (int i = 0; i < header->e_shnum; i++)
// 			if (sections[i].sh_type == SHT_SYMTAB)
// 				return (i);
// 	}
// 	return (-1);
// }

char *get_addr_formatted(long unsigned int addr, int bits, char letter)
{	
	int len = ft_ptrlen(addr);
	if (letter == 'U' || letter == 'w' || letter == 'v')
		len = 0;
	int size = bits - len;
	char *str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return NULL;
	for (int i = 0; i < size; i++) 
	{
		if (len == 0 && (letter == 'U' || letter == 'w' || letter == 'v'))
			str[i] = 32;
		else
			str[i] = 48;
	}
	char *addr_str = convert_addr_to_char(addr, len);
	char *tmp;
	tmp = ft_strjoin(str, addr_str);
	free(str);
	free(addr_str);
	return tmp;
}
unsigned char get_letter(unsigned char type, void* symbol, void* section, int is_64) {
    unsigned char bind = get_symbol_bind(symbol, is_64);
    int readonly = get_section_flags(section, is_64) & SHF_WRITE ? 0 : 1;
    unsigned short shndx = get_symbol_shndx(symbol, is_64);
    int section_type = get_section_type(section, is_64);

    if (shndx == SHN_ABS)
        return ('A');
    else if (bind == STB_GNU_UNIQUE)
        return ('u');
    else if (shndx == SHN_COMMON)
        return (bind == STB_LOCAL ? 'C' : 'c');
    else if (bind == STB_WEAK) {
        // Supposons que vous avez une fonction pour obtenir st_value de manière générique
        unsigned long st_value = get_symbol_value(symbol, is_64);
        if (type == STT_OBJECT)
            return st_value <= 0 ? 'v' : 'V';
        return st_value <= 0 ? 'w' : 'W';
    }
    else if (section_type == SHT_MIPS_DEBUG) {
        if (readonly)
            return ('n');
        return ('N');
    }
    else if (section_type == SHT_NOBITS && get_section_flags(section, is_64) & SHF_ALLOC)
        return (bind == STB_GLOBAL ? 'B' : 'b');
    else if (shndx == SHN_UNDEF)
        return ('U');
    else if (type == STT_FUNC)
        return (bind == STB_LOCAL ? 't' : 'T');
    else if (type == STT_OBJECT || type == STT_NOTYPE) {
        if (readonly) {
            if (get_section_flags(section, is_64) & SHF_EXECINSTR)
                return (bind == STB_GLOBAL ? 'T' : 't');
            return (bind == STB_GLOBAL ? 'R' : 'r');
        }   
        return (bind == STB_GLOBAL ? 'D' : 'd');
    }
    else
        return('?');
}