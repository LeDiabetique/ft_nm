NAME = libft.a

SRC_PATH = ./Sources/

SRC_NAME =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strchr.c ft_strlcpy.c ft_strncmp.c ft_strdup.c \
			ft_strlcat.c ft_strlen.c ft_strnstr.c ft_strrchr.c \
			ft_tolower.c ft_toupper.c ft_calloc.c ft_putchar_fd.c \
		    ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin.c \
			ft_substr.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
			ft_itoa.c ft_split.c ft_lstnew.c ft_lstsize.c \
			ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line.c \
			get_next_line_bonus.c ft_printf.c ft_printhex.c \
			ft_printnbr.c ft_printunsigned.c ft_putptr.c ft_putstr.c \
			ft_putchar.c \

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO = $(patsubst %.c, %.o, $(SRC))

FLAGS = -Wall -Werror -Wextra -I Includes

all: $(NAME)

$(NAME): $(SRCO)
	@ar rcs $(NAME) $(SRCO)
	@echo "\033[92mLibrary Compiled\033[97m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(SRCO) $(SRCBO)
	@echo "\033[93mAll .o Files Removed\033[97m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[95mLibrary Removed\033[97m"

re:	fclean all

.PHONY: all fclean clean re
