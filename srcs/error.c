#include "../includes/ft_nm.h"

void    ft_format_error(char *filename)
{
    write (2, "nm: ", 4);
    write (2, filename, ft_strlen(filename));
    write (2, ": file format not recognized\n", 29);
    return ;
}

void    ft_symbol_error(char *symbol)
{
    write (2, "nm: ", 4);
    write (2, symbol, ft_strlen(symbol));
    write (2, ": no symbols\n", 13);
    return ;
}
void	ft_filename_error(char *filename)
{
    write (2, "nm: '", 5);
    write (2, filename, ft_strlen(filename));
    write (2, "': No such file\n", 16);
    return ;
}

void    ft_directory_error(char *filename)
{
    write (2, "nm: Warning: '", 14);
    write (2, filename, ft_strlen(filename));
    write (2, "' is a directory\n", 17);
    return ;
}

void	ft_error(char *str, int option)
{
    if (option == 1)
        ft_format_error(str);
    else if (option == 2)
        ft_filename_error(str);
    else if (option == 3)
        ft_symbol_error(str);
    else if (option == 4)
        ft_directory_error(str);
    else
        ft_putstr_fd(str, 2);
    return ;
}