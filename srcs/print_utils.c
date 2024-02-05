#include "../includes/ft_nm.h"

static char *convert_addr_to_char(long unsigned int addr, int len)
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


char *get_addr_formatted(long unsigned int addr, int bits, char letter)
{	
	int len = ft_ptrlen(addr);
	if (letter == 'U' || letter == 'w' || letter == 'v')
		len = 0;
	int size = bits - len;
	char *str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return NULL;
	for (int i = 0; i < size; i++) 
	{
		if (len == 0 && (letter == 'U' || letter == 'w' || letter == 'v'))
			str[i] = 32;
		else
			str[i] = 48;
	}
	char *addr_str = convert_addr_to_char(addr, len);
	char *tmp;
	tmp = ft_strjoin(str, addr_str);
	free(str);
	free(addr_str);
	return tmp;
}

unsigned char get_letter(unsigned char type, void* symbol, void* section, int is_64)
{

    unsigned char bind = get_symbol_bind(symbol, is_64);
    // write(2, "OPEN", 5);
    unsigned short shndx = get_symbol_shndx(symbol, is_64);

    if (shndx == SHN_ABS){
        if (bind == STB_LOCAL)
            return ('a');
        return ('A');
    }
    int readonly = get_section_flags(section, is_64) & SHF_WRITE ? 0 : 1;
    int section_type = get_section_type(section, is_64);
    if (bind == STB_GNU_UNIQUE)
        return ('u');
    else if (shndx == SHN_COMMON)
        return (bind == STB_LOCAL ? 'C' : 'c');
    else if (bind == STB_WEAK) {
        unsigned long st_value = get_symbol_value(symbol, is_64);
        if (type == STT_OBJECT)
            return st_value <= 0 ? 'v' : 'V';
        if (shndx == SHN_UNDEF)
            return ('w');
        return st_value <= 0 ? 'w' : 'W';
    }
    else if (section_type == SHT_MIPS_DEBUG) {
        if (readonly)
            return ('n');
        return ('N');
    }
    else if (section_type == SHT_NOBITS && get_section_flags(section, is_64) & SHF_ALLOC)
        return (bind == STB_GLOBAL ? 'B' : 'b');
    else if (shndx == SHN_UNDEF)
        return ('U');
    else if (type == STT_FUNC)
        return (bind == STB_LOCAL ? 't' : 'T');
    else if (type == STT_OBJECT || type == STT_NOTYPE) {
        if (readonly) {
            if (get_section_flags(section, is_64) & SHF_EXECINSTR)
                return (bind == STB_GLOBAL ? 'T' : 't');
            return (bind == STB_GLOBAL ? 'R' : 'r');
        }   
        return (bind == STB_GLOBAL ? 'D' : 'd');
    }
    else
        return('?');
}

void print_nm(t_symbol *sym_array, int size, t_nm *nm)
{
    (void)nm;
    for (int i = 0; i < size; i++) {
        if (nm->flag == 2 && (sym_array[i].type != 'U' && sym_array[i].type != 'w'))
            continue;
        ft_printf("%s %c %s\n", sym_array[i].addr, sym_array[i].type, sym_array[i].name);
        free(sym_array[i].addr);
    }
}