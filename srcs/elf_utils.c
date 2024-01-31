#include "../includes/ft_nm.h"
int	get_symbol_section(Elf64_Ehdr *header, Elf64_Shdr *sections)
{
	for (int i = 0; i < header->e_shnum; i++)
		if (sections[i].sh_type == SHT_SYMTAB)
			return (i);
	return (-1);
}

void	get_addr_formatted(long unsigned int addr, int bits)
{	
	int len = ft_ptrlen(addr);
	int size = bits - len;
	if (len == 0)
	{
		while (bits-- > 0)
			write(1, " ", 1);
		return ;
	}
	for(int i = 0; i < size; i++)
		write(1, "0", 1);
	return ;
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