#ifndef FT_NM_H
# define FT_NM_H
# include <elf.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include "../libft/Includes/libft.h"

typedef struct s_nm
{
	char		*filename;
	int			fd;
	struct stat	buf;
	void		*ptr;
}	t_nm;

void	ft_error(char *str);
int		open_file(t_nm *nm, char *filename);
int		get_elf_format(t_nm *nm);
int		close_file(t_nm *nm);
unsigned char   get_letter(unsigned char type, Elf64_Sym *symbol);
int		get_symbol_section(Elf64_Ehdr *header, Elf64_Shdr *sections);
void	get_addr_formatted(long unsigned int addr, int bits);





#endif