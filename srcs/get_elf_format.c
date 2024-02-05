#include "../includes/ft_nm.h"
static int check_elf_format(unsigned char *ident,char *filename)
{
	 if (ident[EI_MAG0] != ELFMAG0
		|| ident[EI_MAG1] != ELFMAG1
		|| ident[EI_MAG2] != ELFMAG2
		|| ident[EI_MAG3] != ELFMAG3)
	{
		ft_error(filename, 1);
		return (1);
	}
	return (0);
}


int get_elf_format(t_nm * nm)
{
	unsigned char *ident = (unsigned char *)nm->ptr;
	if (check_elf_format(ident, nm->filename) != 0)
		return (1);
	if (ident[EI_CLASS] == ELFCLASS32)
	{
		Elf32_Ehdr *header = (Elf32_Ehdr *)nm->ptr;
		Elf32_Shdr *sections = (Elf32_Shdr *)(nm->ptr + header->e_shoff);
		if (header->e_shoff +(header->e_shentsize * header->e_shnum) > (long unsigned int)nm->buf.st_size)
			return(ft_error(nm->filename, 1), 1);
		if (header->e_shstrndx >= header->e_shnum)
			return(ft_error(nm->filename, 1), 1);
		handle_elf(sections, header, nm, 0);		
	}
	else if (ident[EI_CLASS] == ELFCLASS64)
	{
		Elf64_Ehdr *header = (Elf64_Ehdr *)nm->ptr;
		Elf64_Shdr *sections = (Elf64_Shdr *)(nm->ptr + header->e_shoff);
		if (header->e_shoff +(header->e_shentsize * header->e_shnum) > (long unsigned int)nm->buf.st_size)
			return(ft_error(nm->filename, 1), 1);
		if (header->e_shstrndx >= header->e_shnum)
			return(ft_error(nm->filename, 1), 1);
		handle_elf(sections, header, nm, 1);		
	}
	else
		return(ft_error(nm->filename, 1), 1);
	return (0);
}
