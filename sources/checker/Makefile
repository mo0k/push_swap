# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 17:53:51 by mo0ky             #+#    #+#              #
#    Updated: 2017/12/05 13:10:38 by mo0ky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../checker

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

INC_PATH = includes

INC =	$(INC_PATH)/checker.h \
		$(INC_PATH)/win.h \
		$(INC_PATH)/visual.h \
		../../includes/instructions.h \
		../../includes/my_types.h

SRC_PATH = sources

SRC =	$(SRC_PATH)/checker.c		\
		$(SRC_PATH)/init.c			\
		$(SRC_PATH)/parse.c			\
		$(SRC_PATH)/data.c			\
		$(SRC_PATH)/print.c			\
		$(SRC_PATH)/instruction.c	\
		$(SRC_PATH)/visu.c			\
		$(SRC_PATH)/win.c			\
		$(SRC_PATH)/update.c		\
		$(SRC_PATH)/exit.c			\
		../spe_atoi.c				\
		../already_create.c			\
		../get_min_max.c			\
		../instructions/pa.c		\
		../instructions/pb.c		\
		../instructions/ra.c		\
		../instructions/rb.c		\
		../instructions/rr.c		\
		../instructions/rra.c		\
		../instructions/rrb.c		\
		../instructions/rrr.c		\
		../instructions/sa.c		\
		../instructions/sb.c		\
		../instructions/ss.c

OSRC = $(SRC:.c=.o)

LIBPRINT_PATH = ../libftprintf
LIB = $(LIBPRINT_PATH)/libftprintf.a
LIBFT_PATH = $(LIBPRINT_PATH)/libft

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC) $(INC) Makefile
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIBPRINT_PATH) -lftprintf -lncurses #-g3 -fsanitize=address
	@echo "$(OK_COLOR)checker compiled.$(NO_COLOR)"

$(LIB):
	@echo "Compiling libftprintf..."
	@make -C $(LIBPRINT_PATH)
	@echo "Librairy compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBPRINT_PATH)/$(INC_PATH) -I $(LIBFT_PATH)/$(INC_PATH) -I $(INC_PATH) -I ../../includes -c -o $@ $?
	@echo "Linking file $@"

clean:
	@/bin/rm -f $(OSRC)

fclean: clean
	@if [ -e $(NAME) ]; \
	then echo "Delete checker"; \
	fi;
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
