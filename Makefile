# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ejanssen <ejanssen@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 13:24:29 by ejanssen          #+#    #+#              #
#    Updated: 2022/10/27 23:22:02 by ejanssen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C 					= gcc
MAKE				= make
CFLAGS 				= -Wall -Werror -Wextra
SRC 				= ft_printf.c
SRC					+= ft_printf_char.c
SRC					+= ft_printf_dec.c
SRC					+= ft_printf_str.c

DEPENDENCIES 		= ft_printf.h
OBJECTS				= $(SRC:.c=.o)

NAME				= libftprintf.a

LIBFT_DIR			= ./libft
LIBFT				= libft.a

.PHONY: all
all:  $(LIBFT) $(NAME)

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: $(NAME)
$(NAME):$(OBJECTS)
	cp $(LIBFT_DIR)/$(LIBFT) .
	mv $(LIBFT_DIR)/$(LIBFT) $@
	ar r $@ $^

.PHONY : $(LIBFT)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(OBJECS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

.PHONY: re
re : fclean all
