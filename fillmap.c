/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:23:35 by cpodariu          #+#    #+#             */
/*   Updated: 2017/02/14 18:25:55 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

void	make_letters(t_tetrimino **tetriminos, int len)
{
	int			i;
	int			j;
	int			q;
	t_tetrimino	*t;

	t = *tetriminos;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < t[i].lines)
		{
			q = 0;
			while (q < t[i].rows)
			{
				if (t[i].squares[j][q] == '#')
					t[i].squares[j][q] = 'A' + i;
				q++;
			}
			j++;
		}
		i++;
	}
	*tetriminos = t;
}

int		is_mergeable(t_tetrimino dest, t_tetrimino src, int line, int row)
{
	int	i;
	int	j;

	if (line + src.lines > dest.lines)
		return (0);
	if (row + src.rows > dest.rows)
		return (0);
	i = line;
	while (i < src.lines + line)
	{
		j = row;
		while (j < src.rows + row)
		{
			if (dest.squares[i][j] != '.' &&
					src.squares[i - line][j - row] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	merge(t_tetrimino *d, t_tetrimino src, int line, int row)
{
	int			i;
	int			j;
	t_tetrimino	dest;

	dest = *d;
	i = line;
	while (i < src.lines + line)
	{
		j = row;
		while (j < src.rows + row)
		{
			if (src.squares[i - line][j - row] != '.')
				dest.squares[i][j] = src.squares[i - line][j - row];
			j++;
		}
		i++;
	}
	*d = dest;
}

void	trim_all(t_tetrimino **t, int len)
{
	t_tetrimino	*tetriminos;
	int			i;

	tetriminos = *t;
	i = 0;
	while (i < len)
	{
		trim_tetrimino_rows(&(tetriminos[i]));
		trim_tetrimino_lines(&(tetriminos[i]));
		trim_tetrimino_rows2(&(tetriminos[i]));
		trim_tetrimino_lines2(&(tetriminos[i]));
		i++;
	}
	*t = tetriminos;
}
