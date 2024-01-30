#include "../includes/ft_nm.h"

unsigned char   get_letter(unsigned char type, Elf64_Sym *symbol,)
{
        unsigned char bind = ELF64_ST_BIND(symbol->st_info);
        if (symbol->st_shndx == SHN_UNDEF)
                return ('U');
        else if (bind == STB_WEAK){
            bind = 'W';
            if (symbol->st_shndx == SHN_UNDEF)
                bind = 'w';
        }
        else if (type == SHT_NOBITS)
            bind = STB_GLOBAL ? 'B' : 'b';
        else if (type == STT_FUNC)
            bind = STB_GLOBAL ? 'T' : 't';
        else if (type == STT_OBJECT)
            bind = STB_GLOBAL ? 'D' : 'd';
        else
            return('?');
        return bind;
}