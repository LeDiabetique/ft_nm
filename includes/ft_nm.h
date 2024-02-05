#ifndef FT_NM_H
# define FT_NM_H
# include <elf.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include "../libft/Includes/libft.h"


					/*  NM STRUCT  */		
	typedef struct s_nm
	{
		char		*filename;
		int			fd;
		struct stat	buf;
		void		*ptr;
		int			flag;
	}	t_nm;


					/*  SYMBOL STRUCT  */
	typedef struct s_symbol
	{
		char		*addr;
		char		type;
		char		*name;
	}	t_symbol;


					/*	ERROR FUNCTION  */
	void			ft_error(char *str, int option);


					/*	OPEN / CLOSE FUNCTIONS  */
	int				open_file(t_nm *nm, char *filename);
	int				close_file(t_nm *nm);


					/*	GETTER 32 OR 64 BITS INFO  */
	int				get_shnum(void *header_v, int is_64);
	int				get_sh_type(void *sections_v, int i, int is_64);
	int				get_section_flags(void* section, int is_64);
	int				get_section_type(void* section, int is_64);
	void 			*get_section(void *sections_v, int i, int is_64);
	int				get_section_entsize(void* section, int is_64);
	int				get_section_size(void* section, int is_64);
	int				get_section_offset(void* section, int is_64);
	void			*get_linked_section(void *sections_v, void *symsection, int is_64);
	int				get_st_type(void *symbol_v, int is_64);
	unsigned char	get_symbol_bind(void* symbol, int is_64);
	int				get_symbol_section(void *header, void *sections, int is_64);
	unsigned short	get_symbol_shndx(void* symbol, int is_64);
	int				get_symbol_value(void* symbol, int is_64);
	void 			*get_symbol(void *symtab, int i, int is_64);
	int				get_symbol_name(void *symbol, int is_64);
	unsigned int	get_section_name_string_index(void *header, int is_64);
	unsigned int    get_section_header_entry_size(void *header, int is_64);
	unsigned int	get_section_header_number(void *header, int is_64);
	unsigned long   get_section_header_offset(void *header, int is_64);
	

					/*	STRING FORMAT FUNCTIONS  */
	int				get_elf_format(t_nm *nm);
	unsigned char   get_letter(unsigned char type, void *symbol, void *section, int is_64);
	char			*get_addr_formatted(long unsigned int addr, int bits, char letter);
	void			bubble_sort(t_symbol * sym_array, int i_sym);


					/*	ELF FILE HANDLER  */
	void			handle_elf(void *sections, void *header, t_nm *nm, int is_64);


					/*  PRINT FUNCTION  */
	void			print_nm(t_symbol *sym_array, int size, t_nm *nm);

#endif