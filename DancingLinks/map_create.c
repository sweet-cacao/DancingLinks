#include "dance.h"

t_line	*map_create(t_tetrim *tet, int size) {
    t_line *head;
    t_line *prev;
    t_line *line;
    int n;
    int i;
    int index;
    int idx;

    idx = 0;

    t_block **arr;

    arr = (t_block **) ft_memalloc(size * size * sizeof(t_block *));

    index = 0;
    head = NULL;
    prev = NULL;
    line = NULL;
    while (tet) {
        printf("index = %d\n", index);
        tet->y = 0 - tet->y0;
        while (tet->y < size - tet->y1) {
            tet->x = 0 - tet->x0;
            while (tet->x < size - tet->x1)
            {
                line = (t_line *) ft_memalloc(sizeof(t_line));
                line->index = idx++;

                line->ulink = prev;
                if (prev)
                    prev->dlink = line;
                if (!head)
                    head = line;
                prev = line;

                //line->block = (t_block *)ft_memalloc(4 * sizeof(t_block));
                n = 0;
                while (n < 4) {
                    i = size * (tet->y + tet->block[n].y) + (tet->x + tet->block[n].x);
                    (line->block + n)->column = i;
                    if (arr[i]) {
                        arr[i]->dlink = (line->block + n);
                        (line->block + n)->ulink = arr[i];
                    }
                    arr[i] = (line->block + n);
                    n++;
                }
                tet->x++;
            }
            tet->y++;
        }
        tet = tet->next;
        index++;
    }
    return (head);
}