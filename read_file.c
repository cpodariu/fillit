/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:40:59 by cpodariu          #+#    #+#             */
/*   Updated: 2017/02/14 19:08:57 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillitlib.h"

int			read_file(char **argv, char **buf)
{
	int		file;
	char	*buffer;
	int		len;
	int		bytes_read;

	len = 1000;
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		error();
	buffer = *buf;
	bytes_read = read(file, buffer, len);
	buffer[bytes_read] = 0;
	return (bytes_read);
}

int			validate1(char *str, int len)
{
	int i;
	int j;

	while (len >= 20)
	{
		i = 5;
		while (--i)
		{
			j = 5;
			while (--j)
				if (*str != '.' && *str != '#')
					return (0);
				else
					str++;
			if (*str != '\n')
				return (0);
			str++;
		}
		if (*str == '\n')
			str++;
		len -= 21;
	}
	if (len != -1)
		return (0);
	return (1);
}

t_tetrimino	*init_tetriminos(int len)
{
	t_tetrimino	*tetriminos;
	int			i;

	tetriminos = (t_tetrimino*)malloc(sizeof(t_tetrimino) * (len));
	i = 0;
	while (i < len)
	{
		tetriminos[i].squares = (char**)malloc(sizeof(char*) * 5);
		tetriminos[i].lines = 4;
		tetriminos[i].rows = 4;
		i++;
	}
	return (tetriminos);
}

t_tetrimino	*get_tetriminos(char **buffer, int *len)
{
	t_tetrimino	*tetriminos;
	int			i;
	char		*str;

	str = *buffer;
	*len = (*len + 1) / 21;
	tetriminos = init_tetriminos(*len);
	i = 0;
	while (i < *len)
	{
		tetriminos[i].squares[0] = str;
		tetriminos[i].squares[1] = str + 5;
		tetriminos[i].squares[2] = str + 10;
		tetriminos[i].squares[3] = str + 15;
		str += 21;
		i++;
	}
	return (tetriminos);
}

int			validate2(t_tetrimino *tetriminos, int len)
{
	int i;
	int j;
	int nr;

	while (len)
	{
		nr = 0;
		i = 4;
		while (i)
		{
			j = 4;
			while (j)
			{
				if (tetriminos[len - 1].squares[i - 1][j - 1] == '#')
					nr++;
				j--;
			}
			i--;
		}
		if (nr != 4)
			return (0);
		len--;
	}
	return (1);
}
