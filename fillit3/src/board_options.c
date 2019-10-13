/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 01:08:31 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 03:59:04 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void	board_options_blocks(\
					t_board *self, t_tetrim *tetrim, t_line *line)
{
	t_block		*last;
	t_block		*curr;
	int			index;
	int			column;

	index = 0;
	while (index < 4)
	{
		column = self->size * (tetrim->y + tetrim->blocks[index].y) + \
			(tetrim->x + tetrim->blocks[index].x);
		last = self->columns[column];
		curr = &line->blocks[index];
		curr->column = column;
		curr->line = line;
		if (last)
		{
			last->dlink = curr;
			curr->ulink = last;
		}
		self->columns[column] = curr;
		index++;
	}
}

static inline void	board_options_insert(t_board *self, t_line *line)
{
	t_line		*last;

	last = self->tail;
	if (last)
	{
		line->ulink = last;
		last->dlink = line;
	}
	else
		self->head = line;
	self->tail = line;
}

int					board_options(t_board *self, t_tetrim *tetrim)
{
	t_line		*line;

	self->count = 0;
	while (tetrim)
	{
		tetrim->y = 0 - tetrim->y0;
		while (tetrim->y < self->size - tetrim->y1)
		{
			tetrim->x = 0 - tetrim->x0;
			while (tetrim->x < self->size - tetrim->x1)
			{
				line = (t_line *)ft_memalloc(sizeof(t_line));
				if (!line)
					return (0);
				line->number = self->count;
				board_options_blocks(self, tetrim, line);
				board_options_insert(self, line);
				tetrim->x++;
			}
			tetrim->y++;
		}
		tetrim = tetrim->next;
		self->count++;
	}
	return (1);
}
