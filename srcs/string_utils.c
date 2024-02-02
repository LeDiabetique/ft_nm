#include "../includes/ft_nm.h"


char *convert_addr_to_char(long unsigned int addr, int len)
{
    char *str = malloc(sizeof(char) * len + 1);
    str[len] = '\0';
    for (int i = len - 1; i >= 0; --i) {
        int digit = addr & 0xF;
        str[i] = (digit < 10) ? (digit + '0') : (digit + 'a' - 10);
        addr >>= 4;
    }
    return str;
}

int ft_symcmp(char * sym1, char *sym2)
{
    int i = 0;
    int j = 0;
    if (sym1[i] == '_')
        while (sym1[i] == '_')
            i++;
    if (sym2[j] == '_')
        while (sym2[j] == '_')
            j++;
    while (sym1[i] == sym2[j] && sym1[i] != '\0' && sym2[j] != '\0')
    {
        i++;
        j++;
    }
    return (sym1[i] - sym2[i]);
}
void bubble_sort(t_symbol * sym_array, int i_sym)
{
    t_symbol tmp;

    for (int i = 0; i < i_sym; i++)
    {
        for (int j = 0; j < i_sym - 1; j++)
        {
            if (ft_strncmp(sym_array[j].name, sym_array[j + 1].name, ft_strlen(sym_array[j+1].name)) > 0)
            {
                tmp = sym_array[j];
                sym_array[j] = sym_array[j + 1];
                sym_array[j + 1] = tmp;
            }
        }
    }
}