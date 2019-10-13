/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrim_area.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 08:52:42 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 03:26:22 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Fill the structure with coordinates of left upper and right downer corner
*/

void	tetrim_area(t_tetrim *self)
{
	int		x;
	int		y;
	int		index;

	self->x0 = 3;
	self->y0 = 3;
	self->x1 = 0;
	self->y1 = 0;
	index = 0;
	while (index < 4)
	{
		x = self->blocks[index].x;
		y = self->blocks[index].y;
		if (self->x0 > x)
			self->x0 = x;
		if (self->y0 > y)
			self->y0 = y;
		if (self->x1 < x)
			self->x1 = x;
		if (self->y1 < y)
			self->y1 = y;
		index++;
	}
}
