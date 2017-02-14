#include "fillitlib.h"

t_tetrimino init_empty_tetrimino(int size)
{
	t_tetrimino t;
	int i;
	int j;

	t.squares = (char**)malloc(sizeof(char*) * size);
	i = 0;
	while (i < size)
	{
		t.squares[i] = (char*)malloc(sizeof(char) * size + 1);
		j = 0;
		while (j < size)
			t.squares[i][j++] = '.';
		t.squares[i][j] = 0;
		i++;
	}
	t.lines = size;
	t.rows = size;
	return t;
}

void trim_tetrimino_rows(t_tetrimino *my_tetrimino)
{
	t_tetrimino t;
	int i;

	t = *my_tetrimino;
	i = 0;
	while (i < t.lines)
		if (t.squares[i++][0] == '#')
			return;
	i = 0;
	while (i < t.lines)
		++t.squares[i++];
	t.rows--;
	*my_tetrimino = t;
	if(t.rows > 1)
		return trim_tetrimino_rows(my_tetrimino);
	return;
}

void trim_tetrimino_rows2(t_tetrimino *my_tetrimino)
{
	t_tetrimino t;
	int i;

	t = *my_tetrimino;
	i = 0;
	while (i < t.lines)
		if (t.squares[i++][t.rows - 1] == '#')
			return;
	t.rows--;
	*my_tetrimino = t;
	if (t.rows > 1)
		return trim_tetrimino_rows2(my_tetrimino);
	return;
}

void trim_tetrimino_lines(t_tetrimino *my_tetrimino)
{
	t_tetrimino t;
	int i;

	t = *my_tetrimino;
	i = 0;
	while (i < t.rows)
		if (t.squares[0][i++] == '#')
			return;
	++t.squares;
	t.lines--;
	*my_tetrimino = t;
	if(t.lines > 1)
		return trim_tetrimino_lines(my_tetrimino);
	return;
}

void trim_tetrimino_lines2(t_tetrimino *my_tetrimino)
{
	t_tetrimino t;
	int i;

	t = *my_tetrimino;
	i = 0;
	while (i < t.rows)
		if (t.squares[t.lines - 1][i++] == '#')
			return;
	t.lines--;
	*my_tetrimino = t;
	if(t.lines > 1)
		return trim_tetrimino_lines2(my_tetrimino);
	return;
}
