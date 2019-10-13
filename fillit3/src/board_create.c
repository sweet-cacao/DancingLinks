/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:36:53 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 05:14:51 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline char	*map_create(int size)
{
	char	*self;
	int		index;
	int		length;

	length = (size + 1) * size;
	self = ft_strnew(length);
	if (self)
	{
		index = 0;
		while (index < length)
		{
			if (index % (size + 1) == size)
				self[index] = '\n';
			else
				self[index] = '.';
			index++;
		}
	}
	return (self);
}

t_board				*board_create(int size, t_tetrim *tetrim)
{
	t_board		*self;

	self = (t_board *)ft_memalloc(sizeof(t_board));
	if (self)
	{
		self->size = size;
		self->map = map_create(size);
		self->columns =\
			(t_block **)ft_memalloc(size * size * sizeof(t_block *));
		if (self->map && self->columns)
		{
			if (board_options(self, tetrim))
				return (self);
		}
		board_destroy(&self);
	}
	return (NULL);
}
