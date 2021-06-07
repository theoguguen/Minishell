##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## a
##

SRCDIR	=	src/

BUILTDIR	=	builtins/

SRC	=	$(SRCDIR)mysh.c \
		$(SRCDIR)load2d.c \
		$(SRCDIR)path_to_tab.c \
		$(SRCDIR)get_path.c \
		$(SRCDIR)get_home.c \
		$(SRCDIR)prompt.c \
		$(SRCDIR)my_fork.c \
		$(SRCDIR)my_getnbr.c \
		$(SRCDIR)my_putchar.c \
		$(SRCDIR)my_putstr.c \
		$(SRCDIR)my_strcpy.c \
		$(SRCDIR)my_strcmp.c \
		$(SRCDIR)my_strlen.c \
		$(SRCDIR)my_strcat.c \
		$(SRCDIR)my_strncpy.c \
		$(SRCDIR)my_strncmp.c \
		$(SRCDIR)my_putnstr.c \
		$(SRCDIR)get_pwd.c \
		$(SRCDIR)get_oldpwd.c	\
		$(SRCDIR)change_oldpwd.c	\
		$(SRCDIR)exec_exit.c	\
		$(SRCDIR)my_redirect.c	\
		$(SRCDIR)$(BUILTDIR)my_binary.c \
		$(SRCDIR)$(BUILTDIR)my_commands.c \
		$(SRCDIR)$(BUILTDIR)print_env.c \
		$(SRCDIR)$(BUILTDIR)my_cd.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-Wall -Wextra -W -I includes

all:	$(NAME)

$(NAME):	$(OBJ)
	@gcc -o $(NAME) $(OBJ)

.PHONY: debug
debug: CFLAGS += -g
debug: re

.PHONY: clean
clean:
	@rm -f $(OBJ)

.PHONY: fclean
fclean:	clean
	@rm -f $(NAME)

.PHONY: re
re:	fclean all

.PHONY: redebug
redebug:	fclean debug
