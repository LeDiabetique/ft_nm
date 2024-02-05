#include "../includes/ft_nm.h"

int check_flags(char **av)
{
	int i = 1;
	int flag = -1;
	int fd = 0;
	if ((fd = open(av[i], O_RDONLY)) > 0)
	{
		close(fd);
		return (0);
	}
	if (av[i][0] == '-' && ft_strlen(av[i]) == 2)
	{
		if (av[i][1] == 'p')
			flag = 1;
		else if (av[i][1] == 'u')
			flag = 2;
		else if (av[i][1] == 'a')
			flag = 3;
		else if (av[i][1] == 'r')
			flag = 4;
		else if (av[i][1] == 'g')
			flag = 5;
		else
		{
			ft_error("Error: Invalid flag\n", 0);
			return (-2);
		}
	}
	return (flag);
}

int	main(int ac, char **av)
{
	char	*filename;
	t_nm	nm;
	nm.flag = 0;
	if (ac == 1)
		filename = "a.out";
	if (ac > 1)
	{
		if ((nm.flag = check_flags(av)) > -2)
		{
			if (nm.flag > 0 && ac == 2)
				filename = "a.out";
			else if (ac == 3 && nm.flag != -1)
				filename = av[2];
			else
				filename = av[1];
		}
		else 
			return (1);
	}
	else if (ac > 3)
	{
		ft_error("Error: Invalid number of arguments\n", 0);
		return (1);
	}
	else
		filename = av[1];
	if (open_file(&nm, filename) != 0)
		return (1);
	if (get_elf_format(&nm) != 0)
		return (1);
	if (close_file(&nm) != 0)
		return (1);
	return (0);
}
