# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bconchit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/29 14:08:58 by bconchit          #+#    #+#              #
#    Updated: 2019/10/13 03:49:37 by bconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

INC_DIR		= ./includes
SRC_DIR		= ./src
OBJ_DIR		= ./obj

HEADERS		= fillit.h
SOURCES		= board_create.c \
			  board_destroy.c \
			  board_options.c \
			  board_print.c \
			  board_solve.c \
			  main.c \
			  solve.c \
			  tetrim_area.c \
			  tetrim_count.c \
			  tetrim_create.c \
			  tetrim_destroy.c \
			  tetrim_readfile.c \
			  tetrim_text.c \
			  tetrim_valid.c \

LIBFT		= ./libft

CC			= gcc
WFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR) -I$(LIBFT)/includes
LFLAGS		= -L $(LIBFT)/ -lft

INCS		= $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS		= $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)/
	$(CC) $(WFLAGS) $(IFLAGS) $(LFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p ${@D}
	$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT)/ clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT)/ fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette $(INCS) $(SRCS)

.PHONY: all clean fclean re
