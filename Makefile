.PHONY: all clean fclean re

CC = cc
FLAGS = -Wall -Wextra -Werror 
RM = rm -rf
NAME = pipex

CFILES = Mandatory/pipex.c\
         Mandatory/Error_handle.c\
         Mandatory/exvcmd.c

OBJ = $(patsubst %.c, %.o, $(CFILES))

all: lib $(NAME)

lib:
	@make -C libft

$(OBJ) : %.o: %.c Mandatory/pipex.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : libft/libft.a $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo Making ... Done.

clean:
	@$(RM) $(OBJ)
	@make -C libft clean
	@echo cleaning ... Done.

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean

re: fclean all