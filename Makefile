# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/03 13:54:24 by ngouy             #+#    #+#              #
#    Updated: 2015/05/27 13:27:13 by ngouy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= ft_minishell1

SRC			= \
	   ./Sources/ft_sh1.c\
	   ./Sources/ft_sh11.c\
	   ./Sources/ft_sh12.c\
	   ./Sources/ft_sh13.c\
	   ./Sources/ft_sh14.c\
	   ./Sources/ft_sh15.c\
	   ./Sources/ft_sh16.c\

OBJ			= \
	   ./ft_sh1.o\
	   ./ft_sh11.o\
	   ./ft_sh12.o\
	   ./ft_sh13.o\
	   ./ft_sh14.o\
	   ./ft_sh15.o\
	   ./ft_sh16.o\

CFLAGS		= -Wall -Wextra -ansi -pedantic
OFLAGS		= -O3

RM			= rm -rf

all: $(NAME)

$(NAME):
			make -C ./Libs/libft/
			gcc $(CFLAGS) -c $(SRC)
			gcc $(OBJ) -I ./Includes ./Libs/libft/libft.a -o $(NAME)

clean:
			make clean -C ./Libs/libft/
			$(RM) $(OBJ)

fclean:		clean
			make fclean -C ./Libs/libft/
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
