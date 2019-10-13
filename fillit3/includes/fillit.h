/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:16:07 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 03:50:11 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

# include <stdio.h>

# define MAX_TETRIM 26

typedef struct s_point	t_point;
typedef struct s_tetrim	t_tetrim;
typedef struct s_block	t_block;
typedef struct s_line	t_line;
typedef struct s_board	t_board;

struct					s_point
{
	int			x;
	int			y;
};

struct					s_tetrim
{
	t_tetrim	*next;
	t_point		blocks[4];
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			x;
	int			y;
};

struct					s_block
{
	int			column;
	t_line		*line;
	t_block		*ulink;
	t_block		*dlink;
};

struct					s_line
{
	int			number;
	t_block		blocks[4];
	t_line		*ulink;
	t_line		*dlink;
	t_line		*next;
};

struct					s_board
{
	int			size;
	int			count;
	char		*map;
	t_line		*head;
	t_line		*tail;
	t_block		**columns;
};

t_tetrim				*tetrim_create(char *text);
void					tetrim_destroy(t_tetrim **addr);
int						tetrim_text(t_tetrim *self, char *text);
void					tetrim_area(t_tetrim *self);
int						tetrim_valid(t_tetrim *self);
t_tetrim				*tetrim_readfile(int fd);
int						tetrim_count(t_tetrim *walk);

t_board					*solve(t_tetrim *tetrim);

t_board					*board_create(int size, t_tetrim *tetrim);
void					board_destroy(t_board **addr);
int						board_options(t_board *self, t_tetrim *tetrim);
void					board_print(t_board *self);
int						board_solve(t_board *self);

#endif
