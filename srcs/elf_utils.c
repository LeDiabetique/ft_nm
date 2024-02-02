#include "../includes/ft_nm.h"
int	get_symbol_section(Elf64_Ehdr *header, Elf64_Shdr *sections)
{
	for (int i = 0; i < header->e_shnum; i++)
		if (sections[i].sh_type == SHT_SYMTAB)
			return (i);
	return (-1);
}

char *get_addr_formatted(long unsigned int addr, int bits)
{	
	int len = ft_ptrlen(addr);
	int size = bits - len;
	char *str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return NULL;
	for (int i = 0; i< size; i++) 
	{
		if (len == 0)
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

unsigned char   get_letter(unsigned char type, Elf64_Sym *symbol, Elf64_Shdr *section)
{
		unsigned char bind = ELF64_ST_BIND(symbol->st_info);
		int readonly = section->sh_flags & SHF_WRITE ? 0 : 1;
		if (symbol->st_shndx == SHN_ABS)
			return ('A');
		else if (bind == STB_GNU_UNIQUE)
			return ('u');
		else if (symbol->st_shndx == SHN_COMMON)
			return (bind == STB_LOCAL ? 'C' : 'c');
		else if (bind == STB_WEAK) {
			if (type == STT_OBJECT)
				return symbol->st_value <= 0 ? 'v' : 'V';
			return symbol->st_value <= 0 ? 'w' : 'W';
		}
		else if (section->sh_type == SHT_MIPS_DEBUG)
		{
			if (readonly)
				return ('n');
			return ('N');
		}
		else if (section->sh_type == SHT_NOBITS && section->sh_flags & SHF_ALLOC)
			return (bind == STB_GLOBAL ? 'B' : 'b');
		else if (symbol->st_shndx == SHN_UNDEF)
				return ('U');
		else if (type == STT_FUNC)
			return (bind == STB_LOCAL ? 't' : 'T');
		else if (type == STT_OBJECT || type == STT_NOTYPE)
		{
			if (readonly)
				return (bind == STB_GLOBAL ? 'R' : 'r');
			return (bind == STB_GLOBAL ? 'D' : 'd');
		}
		else
			return(printf("symbol->st_value: %lx\n", symbol->st_value),'?');
		return bind;
}