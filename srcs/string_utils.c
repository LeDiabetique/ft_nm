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
char ft_symtolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return c;
}
char * get_formatted_name(char *name)
{
    char *formatted_name = malloc(sizeof(char) * ft_strlen(name) + 1);
    int j = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (name[i] != '_' && ft_isalnum(name[i]) == 1)
        {
            formatted_name[j++] = ft_symtolower(name[i]);
        }
    }
    formatted_name[j] = '\0';
    return formatted_name;
}

int ft_symcmp(char * name1, char *name2)
{
    int i = 0;
    int j = 0;
    char *sym1 = get_formatted_name(name1);
    char *sym2 = get_formatted_name(name2);
    while (sym1[i] == sym2[j] && sym1[i] != '\0' && sym2[j] != '\0')
    {
        i++;
        j++;
    }
    if (sym1[i] == sym2[j])
    {
        if (ft_strlen(name1) < ft_strlen(name2))
            return (free(sym1), free(sym2), 1);
    }
    int result = sym1[i] - sym2[j];
    return (free(sym1), free(sym2), result);
}
void bubble_sort(t_symbol * sym_array, int i_sym)
{
    t_symbol tmp;
    
    for (int i = 0; i < i_sym; i++)
    {
        for (int j = 0; j < i_sym - 1; j++)
        {
            if (ft_symcmp(sym_array[j].name, sym_array[j + 1].name) > 0)
            {
                tmp = sym_array[j];
                sym_array[j] = sym_array[j + 1];
                sym_array[j + 1] = tmp;
            }
        }
    }
}