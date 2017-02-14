#include "fillitlib.h"

void print_tetrimino(t_tetrimino tetrimino)
{
	int i;
	int j;

	i = 0;
	while (i < tetrimino.lines)
	{
		j = 0;
		while (j < tetrimino.rows)
			ft_putchar(tetrimino.squares[i][j++]);
		ft_putchar('\n');
		i++;
	}
}

int get_neigbors(t_tetrimino tetrimino, int i, int j, char prev)
{
	int total;

	total = 1;
	if (tetrimino.squares[i][j] != '#')
		return (0);
	if (j <= 2 && prev != 'E')
		total += get_neigbors(tetrimino, i, j + 1, 'W');
	if (j >= 1 && prev != 'W')
		total += get_neigbors(tetrimino, i, j - 1, 'E');
	if(i <= 2)
		total += get_neigbors(tetrimino, i + 1, j, 'N');
	return (total);
}

int is_square(t_tetrimino t, int i, int j)
{
	if (i == 3 || j == 3)
		return (0);
	if (t.squares[i][j] != '#' || t.squares[i + 1][j] != '#')
		return (0);
	if (t.squares[i][j + 1] != '#' || t.squares[i + 1][j + 1] != '#')
		return (0);
	return (1);
}

int validate_tetrimino(t_tetrimino tetrimino)
{
	int i;
	int j;
	int nr;

	i = 0;
	while (i < tetrimino.lines)
	{
		j = 0;
		while (j < tetrimino.rows)
		{
			if (tetrimino.squares[i][j] == '#')
			{
				nr = get_neigbors(tetrimino, i, j, 'N');
				if (nr != 4 && !is_square(tetrimino, i, j))
					return (0);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int validate3(t_tetrimino *t, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (validate_tetrimino(t[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
