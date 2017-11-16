# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 17:53:51 by mo0ky             #+#    #+#              #
#    Updated: 2017/11/15 12:43:01 by mo0ky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../../push_swap

CC = clang

CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes

INC =	push_swap.h ../../includes/instructions.h

SRC_PATH = sources

SRC =	$(SRC_PATH)/push_swap.c							\
		$(SRC_PATH)/initialize/app.c					\
		$(SRC_PATH)/initialize/data.c					\
		$(SRC_PATH)/initialize/stack.c					\
		$(SRC_PATH)/initialize/parse.c					\
		$(SRC_PATH)/temp_print.c						\
		$(SRC_PATH)/utils.c								\
		$(SRC_PATH)/clear.c								\
		$(SRC_PATH)/control_commands/push.c				\
		$(SRC_PATH)/control_commands/swap.c				\
		$(SRC_PATH)/control_commands/rotate.c			\
		$(SRC_PATH)/control_commands/reverse_rotate.c	\
		$(SRC_PATH)/resolve/check_result.c				\
		$(SRC_PATH)/resolve/resolve.c					\
		$(SRC_PATH)/resolve/resolve_utils.c				\
		$(SRC_PATH)/resolve/sort.c						\
		$(SRC_PATH)/resolve/command.c					\
		../spe_atoi.c									\
		../already_create.c								\
		../instructions/pa.c							\
		../instructions/pb.c							\
		../instructions/ra.c							\
		../instructions/rb.c							\
		../instructions/rr.c							\
		../instructions/rra.c							\
		../instructions/rrb.c							\
		../instructions/rrr.c							\
		../instructions/sa.c							\
		../instructions/sb.c							\
		../instructions/ss.c							\

OSRC = $(SRC:.c=.o)

LIBPRINT_PATH = ../libftprintf
LIB = $(LIBPRINT_PATH)/libftprintf.a
LIBFT_PATH = $(LIBPRINT_PATH)/libft

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC) $(INC_PATH)/$(INC) Makefile
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIBPRINT_PATH) -lftprintf #-g3 -fsanitize=address
	@echo "$(OK_COLOR)push_swap compiled.$(NO_COLOR)"

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
	then echo "Delete push_swap"; \
	fi;
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re