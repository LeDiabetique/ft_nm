#include "../includes/ft_nm.h"


char *convert_addr_to_char(long unsigned int addr, int len)
{
    char *str = malloc(sizeof(char) * len + 1);
    int i = len -1;
    while (i > -1)
    {
        if (addr % 16 >= 10)
            str[i--] = addr % 16 + 87;
        else
            str[i--] = addr % 16 + 48;
        addr /= 16;
    }
    str[len] = '\0';
    return str;
}