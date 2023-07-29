# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 17:48:45 by idabligi          #+#    #+#              #
#    Updated: 2023/06/17 10:57:42 by idabligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f

HEADER = cub3d.h

FLS = main ft_textures cub3d_utils ft_libft ft_draw\
	ft_find_distance\

FO = $(FLS:=.o)

all : $(NAME)

$(NAME) : $(FO) $(HEADER)
	$(CC) $(FO) $(FLAGS) libmlx42.a -Iinclude -lglfw -L"/Users/idabligi/.brew/opt/glfw/lib/" -o $(NAME) 
	./$(NAME)
	$(RM) $(FO)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

clean :
	$(RM) $(FO)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all

.PHONY : all clean fclean re