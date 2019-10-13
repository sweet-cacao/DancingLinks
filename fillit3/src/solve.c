/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 04:44:12 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/11 22:48:20 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board		*solve(t_tetrim *tetrim)
{
	t_board		*board;
	int			count;
	int			size;

	count = tetrim_count(tetrim);
	if (count > 0 && count <= MAX_TETRIM)
	{
		size = 2;
		while (size * size < count * 4)
			size++;
		while ((board = board_create(size, tetrim)))
		{
			if (board_solve(board))
				return (board);
			board_destroy(&board);
			size++;
		}
	}
	return (NULL);
}
