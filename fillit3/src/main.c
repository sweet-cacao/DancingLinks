/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:36:38 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/11 22:29:52 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_board		*board;
	t_tetrim	*tetrim;
	int			fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		tetrim = tetrim_readfile(fd);
		close(fd);
		if (tetrim)
		{
			board = solve(tetrim);
			tetrim_destroy(&tetrim);
			if (board)
			{
				board_print(board);
				board_destroy(&board);
				return (0);
			}
		}
		ft_putendl("error");
	}
	else
		ft_putendl("usage: fillit file");
	return (0);
}
