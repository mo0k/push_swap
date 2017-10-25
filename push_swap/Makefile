# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 17:53:51 by mo0ky             #+#    #+#              #
#    Updated: 2017/10/25 23:36:00 by mo0ky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes

INC =	push_swap.h

SRC_PATH = sources

SRC =	$(SRC_PATH)/push_swap.c	\
		$(SRC_PATH)/init.c	\
		$(SRC_PATH)/parse.c	\
		$(SRC_PATH)/data.c	\
		$(SRC_PATH)/clear.c	\
		$(SRC_PATH)/print.c	\
		$(SRC_PATH)/control_commands/push.c	\
		$(SRC_PATH)/control_commands/swap.c	\
		$(SRC_PATH)/control_commands/rotate.c	\
		$(SRC_PATH)/control_commands/reverse_rotate.c	\
		$(SRC_PATH)/commands/pa.c	\
		$(SRC_PATH)/commands/pb.c	\
		$(SRC_PATH)/commands/ra.c	\
		$(SRC_PATH)/commands/rb.c	\
		$(SRC_PATH)/commands/rr.c	\
		$(SRC_PATH)/commands/rra.c	\
		$(SRC_PATH)/commands/rrb.c	\
		$(SRC_PATH)/commands/rrr.c	\
		$(SRC_PATH)/commands/sa.c	\
		$(SRC_PATH)/commands/sb.c	\
		$(SRC_PATH)/commands/ss.c

OSRC = $(SRC:.c=.o)

LIBPRINT_PATH = libftprintf
LIB = $(LIBPRINT_PATH)/libftprintf.a
LIBFT_PATH = $(LIBPRINT_PATH)/libft

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC) $(INC_PATH)/$(INC) Makefile
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIBPRINT_PATH) -lftprintf #-g3 -fsanitize=address
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(LIB):
	@echo "Compiling libftprintf..."
	@make -C $(LIBPRINT_PATH)
	@echo "Librairy compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBPRINT_PATH)/$(INC_PATH) -I $(LIBFT_PATH)/$(INC_PATH) -I $(INC_PATH) -c -o $@ $?
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