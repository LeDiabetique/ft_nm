#include "../includes/ft_nm.h"

int	close_file(t_nm *nm)
{
	if (munmap(nm->ptr, nm->buf.st_size) < 0)
	{
		ft_error("Error: File cannot be unmapped\n", 0);
		return (1);
	}
	if (close(nm->fd) < 0)
	{
		ft_error("Error: File cannot be closed\n", 0);
		return (1);
	}
	return (0);
}
