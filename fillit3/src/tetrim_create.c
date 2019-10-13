/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrim_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 08:30:32 by bconchit          #+#    #+#             */
/*   Updated: 2019/09/29 18:27:05 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrim	*tetrim_create(char *text)
{
	t_tetrim	*self;

	self = (t_tetrim *)ft_memalloc(sizeof(t_tetrim));
	if (self)
	{
		if (tetrim_text(self, text))
		{
			tetrim_area(self);
			if (tetrim_valid(self))
				return (self);
		}
	}
	if (self)
		tetrim_destroy(&self);
	return (NULL);
}
