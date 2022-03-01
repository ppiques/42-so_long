# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 14:03:36 by ppiques           #+#    #+#              #
#    Updated: 2021/12/10 20:53:55 by ppiques          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

SRCS_PATH =	$(shell find srcs -type d)

OBJ_DIR = $(BUILD)/obj

LIB_DIR =	mlx
MLX_DIR =	mlx

INC_DIR = $(shell find includes -type d) \
			$(shell find mlx -type d)

BUILD = .objects

vpath %.c $(foreach dir, $(SRCS_PATH), $(dir):)

SRCS = 	so_long.c \
so_long_animated_collectibles_bonus.c \
so_long_background.c so_long_check.c so_long_collectible.c \
so_long_cross_check.c so_long_events.c so_long_exit_sprite.c \
so_long_free.c so_long_get_next_line_utils.c so_long_get_next_line.c \
so_long_initialize.c so_long_map_check.c  so_long_map_generator.c \
so_long_movecount_bonus.c so_long_movement.c so_long_patrol_ennemy.c \
so_long_patrol.c so_long_player_sprite.c so_long_put_wall_sprite.c \
so_long_render_next_frame.c so_long_utils.c so_long_utils2.c \
so_long_player_firing.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

LIB = mlx_Linux

MFLAGS =	-lXext -lX11 -lm
CFLAGS =	-Wall -Werror -Wextra
BFLAGS =	-DBONUS=1
NOBFLAGS =	-DBONUS=0

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib)) \
				$(MFLAGS)

all :
	@make BONUS=$(NOBFLAGS) $(NAME)

$(NAME) : $(OBJS)
	@cc $(CFLAGS) $(BONUS) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "Executable successfully created\n"

$(OBJ_DIR)/%.o : %.c | $(BUILD)
	@cc $(CFLAGS) $(BONUS) -c $< $(IFLAGS) -o $@

$(BUILD):
	@mkdir $@ $(OBJ_DIR)
	@echo "Object directory created\n"
	@echo "Compiling..\n"

clean :
	@rm -rf $(BUILD)
	@echo "Object directory deleted\n"

fclean : clean
	@rm -rf $(NAME)
	@echo "Executable removed\n"

bonus : fclean
	@make BONUS=$(BFLAGS) $(NAME)

re : fclean all

.PHONY:		bonus all clean fclean re
