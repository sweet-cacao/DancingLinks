#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_col    t_col;
typedef struct s_block  t_block;
typedef struct s_map    t_map;

struct      s_block
{
    int ind_block;
    int     coord;
    t_block *down;
    t_block *up;
};

struct      s_col
{
    int ind_col;
    t_col *down;
};

struct      s_map
{
    int     last_ind;
    t_col     *col;
    t_block   *block[4];
    t_map *up;
    t_map *down;
};

t_map *create_map(size)
{
    t_map *map;
    t_col *col;
    t_block *block;
    t_block *block1;
    t_block *block2;
    t_block *block3;

    map = (t_map *)malloc(sizeof(t_map *));
    col = (t_col *)malloc(sizeof(t_col *));
    block = (t_block *)malloc(sizeof(t_block *));
    block1 = (t_block *)malloc(sizeof(t_block *));
    block2 = (t_block *)malloc(sizeof(t_block *));
    block3 = (t_block *)malloc(sizeof(t_block *));
    col->ind_col = 1;
    col->down = NULL;
    map->down = NULL;
    map->up = NULL;
    map->last_ind = size;
    map->col = col;
    map->block[0] = block;
    map->block[1] = block1;
    map->block[2] = block2;
    map->block[3] = block3;
    map->block[0]->ind_block = 1;
    map->block[0]->coord = 0;
    map->block[1]->ind_block = 1;
    map->block[1]->coord = 1;
    map->block[2]->ind_block = 1;
    map->block[2]->coord = 3;
    map->block[3]->ind_block = 1;
    map->block[3]->coord = 4;
    return (map);
}

int main() {
    t_map *map;
    t_map *map2;

    map = create_map(3);
    map2 = create_map(3);
    map2->block[0]->ind_block = 1;
    map2->block[0]->coord = 0;
    map2->block[1]->ind_block = 1;
    map2->block[1]->coord = 1;
    map2->block[2]->ind_block = 1;
    map2->block[2]->coord = 3;
    map2->block[3]->ind_block = 1;
    map2->block[3]->coord = 4;

    printf("ind_col = %d\n, last_ind = %d\n, ind_block = %d\n, block[%d, %d, %d, %d]\n", map->col->ind_col, map->last_ind, map->block[0]->ind_block, map->block[0]->coord, map->block[1]->coord, map->block[2]->coord, map->block[3]->coord);
/*    int			fd;
    t_tetrim	*tet;
    t_line		*head;

    fd = open("12_hard.txt", O_RDONLY);
    tet = tetrim_readfile(fd);
    close(fd);
    head = map_create(tet, 7);
    recursive_ind(head, head->index)
 */   return (0);
}