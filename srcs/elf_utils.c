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

unsigned char   get_letter(unsigned char type, Elf64_Sym *symbol)
{
		unsigned char bind = ELF64_ST_BIND(symbol->st_info);
		if (symbol->st_shndx == SHN_UNDEF)
				return ('U');
		else if (bind == STB_WEAK){
			bind = 'W';
			if (symbol->st_shndx == SHN_UNDEF)
				bind = 'w';
		}
		else if (type == SHT_NOBITS)
			bind = STB_GLOBAL ? 'B' : 'b';
		else if (type == STT_FUNC)
			bind = STB_GLOBAL ? 'T' : 't';
		else if (type == STT_OBJECT)
			bind = STB_GLOBAL ? 'D' : 'd';
		else
			return('?');
		return bind;
}