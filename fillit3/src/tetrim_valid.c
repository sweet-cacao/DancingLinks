/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrim_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 08:55:08 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 03:28:26 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Validation of tetramino, it takes an array of 4 indexes of a block
** turns them into coordinates (x, y) and checks if they are paired (have
** a pair on the right, left, up or down) if they have 3 or more pairs
** (all tetraminoes have 3 pairs and the square has four, the block is valid)
*/

static inline int	paired(t_point a, t_point b)
{
	return ((a.x + 1 == b.x && a.y == b.y) || (a.x == b.x && a.y + 1 == b.y));
}

int					tetrim_valid(t_tetrim *self)
{
	int		count;

	count = 0;
	count += paired(self->blocks[0], self->blocks[1]);
	count += paired(self->blocks[0], self->blocks[2]);
	count += paired(self->blocks[0], self->blocks[3]);
	count += paired(self->blocks[1], self->blocks[2]);
	count += paired(self->blocks[1], self->blocks[3]);
	count += paired(self->blocks[2], self->blocks[3]);
	return (count > 2);
}
