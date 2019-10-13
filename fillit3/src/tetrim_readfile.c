/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrim_readfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:19:56 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 03:47:34 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline t_tetrim	*recursive(int fd)
{
	t_tetrim	*self;
	char		buff[20];
	int			ret;

	ret = read(fd, buff, 20);
	if (ret == 20)
	{
		self = tetrim_create(buff);
		if (self)
		{
			ret = read(fd, buff, 1);
			if (ret == 0)
				return (self);
			if (ret == 1 && buff[0] == '\n')
			{
				self->next = recursive(fd);
				if (self->next)
					return (self);
			}
			tetrim_destroy(&self);
		}
	}
	return (NULL);
}

t_tetrim				*tetrim_readfile(int fd)
{
	return (recursive(fd));
}
