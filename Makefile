# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 17:19:46 by ppiques           #+#    #+#              #
#    Updated: 2021/09/16 17:29:07 by ppiques          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= Hello_world.c

OBJS 	= $(SRCS:.c=.o)

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

PATH_MLX= mlx

FLAGS	= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -W

all:	$(NAME)

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) ${OBJS_M} $(FLAGS)

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re