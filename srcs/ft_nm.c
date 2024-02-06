#include "../includes/ft_nm.h"

int check_flags(char **av, int ac,t_nm *nm)
{
	int i = 1;
	int j = 0;
	int fd = 0;
	nm->args.a = 0;
	nm->args.g = 0;
	nm->args.p = 0;
	nm->args.r = 0;
	nm->args.u = 0;
	
	while (i < ac)
	{
		if (av[i][0] == '-' && ft_strlen(av[i]) == 2)
		{
			if ((fd = open(av[i], O_RDONLY)) > 0 && ac == 2)
			{
				close(fd);
				nm->args.files[j++] = av[i++];
				nm->args.count++;
				continue;
			}
			if (av[i][1] == 'p')
				nm->args.p = 1;
			else if (av[i][1] == 'u')
				nm->args.u = 1;
			else if (av[i][1] == 'a')
				nm->args.a = 1;
			else if (av[i][1] == 'r')
				nm->args.r = 1;
			else if (av[i][1] == 'g')
				nm->args.g = 1;
			else
			{
				ft_error("Error: Invalid flag\n", 0);
				return (-1);
			}
			nm->has_flag = 1;
			i++;
		}
		else
		{
			nm->args.files[j++] = av[i++];
			nm->args.count++;
		}
	}
	return (nm->has_flag);
}

int	main(int ac, char **av)
{
	char	*filename;
	t_nm	nm;
	int i = 0;

	nm.args.files = malloc(sizeof(char *) * ac);
	if (!nm.args.files)
	{
		ft_error("Error: Malloc failed\n", 0);
		return (-1);
	}
	nm.args.files[i] = "a.out";
	if (ac > 1)
	{
		if ((nm.has_flag = check_flags(av, ac, &nm)) < 0)
			return (1);
	}
	if (nm.args.count == 0)
		nm.args.count = 1;
	while (i < nm.args.count)
	{
		filename = nm.args.files[i++];
		if (open_file(&nm, filename) != 0)
			continue;
		if (get_elf_format(&nm) != 0)
			continue;
		if (close_file(&nm) != 0)
			continue;
	}
	free(nm.args.files);
	return (0);
}
