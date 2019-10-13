/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 08:17:44 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 03:16:15 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	board_destroy(t_board **addr)
{
	t_line		*line;
	t_line		*walk;

	if (addr && *addr)
	{
		ft_memdel((void **)&(*addr)->map);
		ft_memdel((void **)&(*addr)->columns);
		walk = (*addr)->head;
		while (walk)
		{
			line = walk;
			walk = walk->dlink;
			ft_memdel((void **)&line);
		}
		ft_memdel((void **)addr);
	}
}
