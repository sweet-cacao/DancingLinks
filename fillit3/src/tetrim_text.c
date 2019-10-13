/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrim_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 08:53:27 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 03:28:35 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Is used in tetrim_create to check if the tetrimino contains \nin the
** right places and includes only . and #
*/

int		tetrim_text(t_tetrim *self, char *text)
{
	int		count;
	int		index;

	count = 0;
	index = 0;
	while (index < 20)
	{
		if (index % 5 == 4)
		{
			if (text[index] != '\n')
				return (0);
		}
		else
		{
			if (text[index] != '#' && text[index] != '.')
				return (0);
			if (text[index] == '#' && count++ < 4)
			{
				self->blocks[count - 1].x = (index - (index / 5)) % 4;
				self->blocks[count - 1].y = (index - (index / 5)) / 4;
			}
		}
		index++;
	}
	return (count == 4);
}
