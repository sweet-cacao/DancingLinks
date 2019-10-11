#include "dance.h"

int     recursive_ind(t_line **map, int ind)
{
    if (check_free_ind(&map, (*map)->ind) == 0)
        return (0);
    choose_line(&map, (*map)->ind);//chooses the first possible line of this index and covers all other possibilities of the same index
    if (shorten_map(&map, (*map)->ind) == 0) //include undo_map(&map, (*map)->ind);//undo that was done on previous operation
    {
        hide_line(&map, (*map)->ind);
        unhide_lines(&map, (*map)->ind);
        recursive_ind(&map, (*map)->ind);
    }
    else if (ind != (*map)->last_ind)
        recursive_ind(&map, (*map)->ind + 1);
    else
    {
        print_list(map);
        return (1);
    }
}

int     dancing_solver(t_line **map, int size)
{
    map_create(map, size);
    while (!(recursive_ind(map, (*map)->ind)))
    {
        destroy_map(map, size);
        dancing_solver(map, size++);
    }
}