#include "../includes/ft_nm.h"
static int check_elf_format(unsigned char *ident)
{
	 if (ident[EI_MAG0] != ELFMAG0
		|| ident[EI_MAG1] != ELFMAG1
		|| ident[EI_MAG2] != ELFMAG2
		|| ident[EI_MAG3] != ELFMAG3)
	{
		ft_error("Error: The file isn't an ELF\n");
		return (1);
	}
	// write(1, "This file is an ELF\n", ft_strlen("This file is an ELF\n"));
	return (0);
}

static void handle_64_bits(Elf64_Shdr *sections, Elf64_Ehdr *header, t_nm *nm)
{
	Elf64_Shdr *symsection = NULL;
	char *strtab = NULL;
	int j = -1;
	if ((j = get_symbol_section(header, sections)) >= 0)
	{
			symsection = &sections[j];
			strtab = (char *)(nm->ptr + sections[symsection->sh_link].sh_offset);
	}
	if (strtab && symsection)
	{
		Elf64_Sym *symtab = (Elf64_Sym *)(nm->ptr + symsection->sh_offset);
		int sym_size = symsection->sh_size / symsection->sh_entsize;
		t_symbol *sym_array = malloc(sym_size * sizeof(t_symbol));
		if (!sym_array)
			return ft_error("Error: Malloc failed\n");
		int i_sym = 0;
		for(int i = 0; i < sym_size; i++)
		{
			Elf64_Sym *symbol = &symtab[i];
			if (!strtab[symbol->st_name])
				continue;
			unsigned char type = ELF64_ST_TYPE(symbol->st_info);
			if (type == STT_FUNC || type == STT_OBJECT || symbol->st_shndx == SHN_UNDEF || type != STT_FILE)
			{
				unsigned char letter = get_letter(type, symbol, &sections[symbol->st_shndx]);
				char *addr = get_addr_formatted(symbol->st_value, 16, letter);
				char *name = &strtab[symbol->st_name];
				sym_array[i_sym].addr = addr;
				sym_array[i_sym].type = letter;
				sym_array[i_sym].name = name;
				i_sym++;
			}
		}
		bubble_sort(sym_array, i_sym);
		for (int i = 0; i < i_sym; i++)
		{
			ft_printf("%s %c %s\n", sym_array[i].addr, sym_array[i].type, sym_array[i].name);
			free(sym_array[i].addr);
		}
		free(sym_array);
	}
}

int get_elf_format(t_nm * nm)
{
	unsigned char *ident = (unsigned char *)nm->ptr;
	if (check_elf_format(ident) != 0)
		return (1);
	if (ident[EI_CLASS] == ELFCLASS32)
	{
		// write(1, "x86_32 file\n", 12);
		Elf32_Ehdr *header = (Elf32_Ehdr *)nm->ptr;
		Elf32_Shdr *sections = (Elf32_Shdr *)(nm->ptr + header->e_shoff);
		(void)sections;
	}
	else if (ident[EI_CLASS] == ELFCLASS64)
	{
		// write(1, "x64 file\n", 9);
		Elf64_Ehdr *header = (Elf64_Ehdr *)nm->ptr;
		Elf64_Shdr *sections = (Elf64_Shdr *)(nm->ptr + header->e_shoff);
		handle_64_bits(sections, header, nm);		
	}
	else
		return(ft_error("Error: Wrong bits format\n"), 1);
	return (0);
}
