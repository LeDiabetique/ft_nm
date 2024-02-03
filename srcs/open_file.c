#include "../includes/ft_nm.h"

int	open_file(t_nm *nm, char *filename)
{
	nm->filename = filename;
	nm->fd = open(nm->filename, O_RDONLY);
	if (nm->fd < 0)
	{
		ft_error(nm->filename, 2);
		return (1);
	}
	nm->buf = (struct stat){0};
	if (fstat(nm->fd, &nm->buf) < 0)
	{
		ft_error("Error: File cannot be read\n", 0);
		return (1);
	}
	nm->ptr = mmap(0, nm->buf.st_size, PROT_READ, MAP_PRIVATE, nm->fd, 0);
	if (nm->ptr == MAP_FAILED)
	{
		// ft_error("Error: File cannot be mapped\n", 0);
		return (1);
	}
	return (0);
}
