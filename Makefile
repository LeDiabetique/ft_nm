NAME        := ft_nm

CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror 
RM		    := rm -f

SRC_DIR		:= srcs/
SRCS		:= $(addprefix $(SRC_DIR), ft_nm.c open_file.c close_file.c get_elf_format.c \
					print_utils.c sort_utils.c error.c get_elf_info.c handle_elf.c )
INC_DIR		:= includes/

OBJ_DIR		:= ./obj/
OBJS 		:= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

GREEN		:= \033[92m
YELLOW		:= \033[93m
PURPLE 		:= \033[95m

${NAME}:	${OBJS}
	@make -C libft
	@${CC} ${FLAGS} -o ${NAME} ${OBJS} libft/libft.a
	@echo "$(PURPLE)Executable $(GREEN)ft_nm created"

all:		${NAME}

clean:
	@make clean -C libft
	@$(RM) $(OBJ_DIR)*.o
	@[ -d $(OBJ_DIR) ] && rmdir $(OBJ_DIR) || true
	@echo "$(YELLOW)All .o Files inside ft_nm directory deleted"

fclean:
	@make fclean -C libft
	@$(RM) $(OBJ_DIR)*.o
	@[ -d $(OBJ_DIR) ] && rmdir $(OBJ_DIR) || true
	@${RM} ${NAME}
	@echo "$(PURPLE)$(NAME) $(YELLOW)and .o files inside ft_nm directory deleted"

re:	fclean all

.PHONY: all clean fclean re