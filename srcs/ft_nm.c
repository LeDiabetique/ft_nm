#include "../includes/ft_nm.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return ;
}

int	main(int ac, char **av)
{
	t_nm	nm;
	if (ac != 2)
	{
		ft_error("Error: Invalid number of arguments\n");
		return (1);
	}
	if (open_file(&nm, av[1]) != 0)
		return (1);
	if (get_elf_format(&nm) != 0)
		return (1);
	if (close_file(&nm) != 0)
		return (1);
	return (0);
}
