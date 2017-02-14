#include "fillitlib.h"
#include <stdlib.h>

t_tetrimino generate_by_size(int size)
{
	char *str;
	t_tetrimino tetrimino;
	int i;

	str = (char *)malloc(sizeof(char) * size * size + 1);
	tetrimino.lines = size;
	tetrimino.rows = size;
	tetrimino.squares = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size * size)
	{
		str[i] = '.';
		if (i % size == 0)
			tetrimino.squares[i / size] = str + i;
		i++;
	}
	return (tetrimino);
}

void free_map(t_tetrimino *tetrimino, int n)
{
	int i;
	int j;
	t_tetrimino t;

	t = *tetrimino;
	i = 0;
	while (i < t.lines)
	{
		j = 0;
		while (j < t.rows)
		{
			if (t.squares[i][j] == 'A' + n)
				t.squares[i][j] = '.';
			j++;
		}
		i++;
	}
	*tetrimino = t;
}

void backtracking(t_tetrimino *the_map, t_tetrimino *t, int len, int n)
{
	int i;
	int j;
	t_tetrimino map;

	map = *the_map;
	i = 0;
	while(i < map.lines)
	{
		j = 0;
		while (j < map.rows)
		{
			free_map(&map, n);
			if (is_mergeable(map, t[n], i, j))
			{
				merge(&map, t[n], i, j);
				if (len == n + 1)
				{
					print_tetrimino(map);
					exit(0);
				}
				backtracking(&map, t, len, n + 1);
			}
			j++;
		}
		i++;
	}
}

void fillit(t_tetrimino *t, int len)
{
	int dim;
	t_tetrimino map;

	dim = 2;
	while (1)
	{
		map = generate_by_size(dim);
		backtracking(&map, t, len, 0);
		dim++;
	}
}
