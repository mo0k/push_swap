# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 19:25:33 by mo0ky             #+#    #+#              #
#    Updated: 2017/11/13 22:42:39 by mo0ky            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER_PATH = sources/checker
CHECKER = checker

PUSH_SWAP_PATH = sources/push_swap
PUSH_SWAP = push_swap

LIBPRINT_PATH = sources/libftprintf
LIB = $(LIBPRINT_PATH)/libftprintf.a

all: name

name: 
	@make -C $(LIBPRINT_PATH)
	@make -C $(CHECKER_PATH)
	@make -C $(PUSH_SWAP_PATH)

clean:
	@make clean -C $(LIBPRINT_PATH)
	@make clean -C $(CHECKER_PATH)
	@make clean -C $(PUSH_SWAP_PATH)

fclean: clean
	@make fclean -C $(LIBPRINT_PATH)
	@make fclean -C $(CHECKER_PATH)
	@make fclean -C $(PUSH_SWAP_PATH)

re: fclean all

.PHONY: all clean fclean re