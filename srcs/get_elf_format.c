#include "../includes/ft_nm.h"

static int check_elf_format(unsigned char *ident,char *filename)
{
	 if (ident[EI_MAG0] != ELFMAG0
		|| ident[EI_MAG1] != ELFMAG1
		|| ident[EI_MAG2] != ELFMAG2
		|| ident[EI_MAG3] != ELFMAG3)
		return (ft_error(filename, 1), 1);
	if (ident[EI_DATA] != ELFDATA2LSB && ident[EI_DATA] != ELFDATA2MSB)
		return (ft_error(filename, 1), 1);
	if (ident[EI_VERSION] != EV_CURRENT)
		return (ft_error(filename, 1), 1);
	return (0);
}

int get_elf_format(t_nm * nm)
{
	unsigned char *ident = (unsigned char *)nm->ptr;
	if (check_elf_format(ident, nm->filename) != 0)
		return (1);
	int is_64 = ident[EI_CLASS] == ELFCLASS64;
	if (ident[EI_CLASS] != ELFCLASS32 && ident[EI_CLASS] != ELFCLASS64)
		return(ft_error(nm->filename, 1), 1);
	void *header = nm->ptr;
    unsigned long e_shoff = get_section_header_offset(header, is_64);
    unsigned int e_shnum = get_section_header_number(header, is_64);
    unsigned int e_shentsize = get_section_header_entry_size(header, is_64);
    unsigned int e_shstrndx = get_section_name_string_index(header, is_64);
	if (e_shoff + (e_shentsize * e_shnum) > (long unsigned int)nm->buf.st_size)
    {
		if (is_64)
			return (ft_error(nm->filename, 5), ft_error(nm->filename, 1), 1);
		return (ft_error(nm->filename, 3), 1);
	}
	if (e_shstrndx >= e_shnum)
    {
		ft_error(nm->filename, 1);
		return (1);
	}	
	void *sections = (void *)((char *)nm->ptr + e_shoff);
    handle_elf(sections, header, nm, is_64);
	return (0);
}
