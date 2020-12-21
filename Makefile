# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouroum <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/24 15:48:52 by ibouroum          #+#    #+#              #
#    Updated: 2019/12/26 00:08:46 by ibouroum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CFLAGS = -Wall -Wextra -Werror

HEAD = fractol.h

SRC = src/*.c

OBJ = *.o

all:
	make -C libft/
	gcc -c $(SRC)
	gcc $(CFLAGS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit  $(OBJ) libft/libft.a -o $(NAME)
clean:
	     make -C libft/ clean
		 rm -f $(OBJ)
fclean: clean
	        make -C libft/ fclean
			rm $(NAME)

re: fclean all
