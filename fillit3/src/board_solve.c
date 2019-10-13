/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconchit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 08:00:56 by bconchit          #+#    #+#             */
/*   Updated: 2019/10/13 06:04:49 by bconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static inline void		print_line(t_board *self, t_line *walk)
{
	if (!self)
	printf(
		"%d\t%14p,%14p,%14p\t" \
		"%d\t%14p,%14p,%14p\t" \
		"%d\t%14p,%14p,%14p\t" \
		"%d\t%14p,%14p,%14p\t" \
		"%d\t%14p,%14p,%14p\t" \
		"\n",
		walk->number,
		walk->ulink,
		walk,
		walk->dlink,
		(walk->blocks + 0)->column,
		(walk->blocks + 0)->ulink,
		(walk->blocks + 0),
		(walk->blocks + 0)->dlink,
		(walk->blocks + 1)->column,
		(walk->blocks + 1)->ulink,
		(walk->blocks + 1),
		(walk->blocks + 1)->dlink,
		(walk->blocks + 2)->column,
		(walk->blocks + 2)->ulink,
		(walk->blocks + 2),
		(walk->blocks + 2)->dlink,
		(walk->blocks + 3)->column,
		(walk->blocks + 3)->ulink,
		(walk->blocks + 3),
		(walk->blocks + 3)->dlink
	);

	int		index;

	index = 0;
	while (index < 4)
	{
		int column = walk->blocks[index].column;
		column = column + (column / self->size);
		self->map[column] = 'A' + walk->number;
		index++;
	}
}


static inline void		line_cover(t_line *self)
{
	t_block		*curr;
	int			index;

	if (self)
	{
		if (self->ulink)
			self->ulink->dlink = self->dlink;
		if (self->dlink)
			self->dlink->ulink = self->ulink;
		index = 0;
		while (index < 4)
		{
			curr = &self->blocks[index];
			if (curr->ulink)
				curr->ulink->dlink = curr->dlink;
			if (curr->dlink)
				curr->dlink->ulink = curr->ulink;
			index++;
		}
	}
}

static inline void		line_uncover(t_line *self)
{
	t_block		*curr;
	int			index;

	if (self)
	{
		if (self->ulink)
			self->ulink->dlink = self;
		if (self->dlink)
			self->dlink->ulink = self;
		index = 0;
		while (index < 4)
		{
			curr = &self->blocks[index];
			if (curr->ulink)
				curr->ulink->dlink = curr;
			if (curr->dlink)
				curr->dlink->ulink = curr;
			index++;
		}
	}	
}

static inline void		uncover(t_board *self, t_line **asave)
{
	t_line		*line;
	
	if (self)
	{
		while (*asave)
		{
			line = *asave;
			*asave = line->next;
			line->next = NULL;
			line_uncover(line);
		}
	}
}

static inline int	cover(t_board *self, t_line *walk, t_line **asave)
{
	t_line		*line;
	t_block		*curr;
	int			index;
	int			number_ulink;
	int			number_dlink;

	(*asave) = NULL;
	index = 0;
	while (index < 4)
	{		
		curr = walk->blocks[index].dlink;
		while (curr)
		{
			line = curr->line;
			number_ulink = (line->ulink ? line->ulink->number : -1);
			number_dlink = (line->dlink ? line->dlink->number : self->count);
			if (number_ulink + 2 <= number_dlink)
			{
				//printf("number_ulink = %d, number_dlink = %d\n", number_ulink, number_dlink);

				return (0);
			}
			line_cover(line);
			line->next = (*asave);
			(*asave) = line;
			curr = curr->dlink;
		}
		index++;
	}
	return (1);
}

static inline int		line_count(t_line *walk)
{
	int			count;

	count = 0;
	while (walk)
	{
		walk = walk->dlink;
		count++;
	}
	return (count);
}

// static inline int		save_count(t_line *walk)
// {
// 	int			count;

// 	count = 0;
// 	while (walk)
// 	{
// 		walk = walk->next;
// 		count++;
// 	}
// 	return (count);
// }

static inline int		recursive(t_board *self, t_line *walk, int number)
{
	t_line		*save;
	int			ret;

	// if (number == 5)
	// 	return (1);
	
	if (self->count == number)
	{
		printf("===END===\n");
		return (1);
	}
	//printf("%d\n", number);
	while (walk && walk->number < number)
		walk = walk->dlink;
	
	while (walk && walk->number == number)
	{
		// print_line(self, walk);
		// print_line(self, walk->dlink);
		// print_line(self, walk->dlink->dlink);
		//printf("count = %d\n", line_count(self->head));
		//printf("number = %d, count = %d\n", number, line_count(walk));
		ret = cover(self, walk, &save);
		// printf("count = %d\n", line_count(self->head));
		// printf("number = %d, save count = %d\n", number, save_count(save));
		if (ret)
			ret = recursive(self, walk, number + 1);
		uncover(self, &save);
		// printf("count = %d\n", line_count(self->head));
		// printf("number = %d, save count = %d\n", number, save_count(save));
		if (ret)
		{
			print_line(self, walk);
			return (1);
		}		
		walk = walk->dlink;
	}
	return (0);
}

int						board_solve(t_board *self)
{
	int			ret;

	printf("%d, %d\n", self->size, line_count(self->head));
	ret = recursive(self, self->head, 0);
	printf("%d, %d\n", self->size, line_count(self->head));
	return (ret);
}
