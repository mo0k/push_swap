# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 17:53:51 by mo0ky             #+#    #+#              #
#    Updated: 2017/10/15 20:59:20 by mo0ky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = clang

CFLAGS = -Wall -Wextra -Werror -g3

INC_PATH = includes

INC =	$(INC_PATH)/checker.h

SRC_PATH = sources

SRC =	$(SRC_PATH)/checker.c		\
		$(SRC_PATH)/init.c			\
		$(SRC_PATH)/data.c			\
		$(SRC_PATH)/print.c			\
		$(SRC_PATH)/instruction.c	\
		$(SRC_PATH)/commandes/pa.c	\
		$(SRC_PATH)/commandes/pb.c	\
		$(SRC_PATH)/commandes/ra.c	\
		$(SRC_PATH)/commandes/rb.c	\
		$(SRC_PATH)/commandes/rr.c	\
		$(SRC_PATH)/commandes/rra.c	\
		$(SRC_PATH)/commandes/rrb.c	\
		$(SRC_PATH)/commandes/rrr.c	\
		$(SRC_PATH)/commandes/sa.c	\
		$(SRC_PATH)/commandes/sb.c	\
		$(SRC_PATH)/commandes/ss.c

OSRC = $(SRC:.c=.o)

LIBPRINT_PATH = libftprintf
LIB = $(LIBPRINT_PATH)/libftprintf.a
LIBFT_PATH = $(LIBPRINT_PATH)/libft

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC) $(INC) Makefile
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIBPRINT_PATH) -lftprintf #-g3 -fsanitize=address
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(LIB):
	@echo "Compiling libftprintf..."
	@make -C $(LIBPRINT_PATH)
	@echo "Librairy compiled."

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBPRINT_PATH)/$(INC_PATH) -I $(LIBFT_PATH)/$(INC_PATH) -I $(INC_PATH) -c -o $@ $?
	@echo "Linking file $@"

clean:
	@make clean -C $(LIBPRINT_PATH)
	@/bin/rm -f $(OSRC)
	@echo "Cleaning temporary files."

fclean: clean
	@make fclean -C $(LIBPRINT_PATH)
	@/bin/rm -f $(NAME)
	@echo "Delete $(NAME) file."

re: fclean all

.PHONY: all clean fclean re
