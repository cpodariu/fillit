/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:49:25 by cpodariu          #+#    #+#             */
/*   Updated: 2017/02/14 18:55:30 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLITLIB_H
# define FILLITLIB_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define T_TET t_tetrimino

typedef struct	s_tetrimino
{
	char		**squares;
	int			lines;
	int			rows;
}				t_tetrimino;

int				read_file(char **argv, char **buffer);
int				validate1(char *str, int len);
T_TET			*get_tetriminos(char **buffer, int *len);
int				validate2(t_tetrimino *tetriminos, int len);
void			print_tetrimino(t_tetrimino tetrimino);
int				validate_tetrimino(t_tetrimino tetrimino);
T_TET			init_empty_tetrimino(int size);
void			trim_tetrimino_rows(t_tetrimino *my_tetrimino);
void			trim_tetrimino_lines(t_tetrimino *my_tetrimino);
void			trim_tetrimino_rows2(t_tetrimino *my_tetrimino);
void			trim_tetrimino_lines2(t_tetrimino *my_tetrimino);
T_TET			generate_by_size(int size);
int				is_mergeable(T_TET dest, T_TET src, int line, int row);
void			merge(t_tetrimino *d, t_tetrimino src, int line, int row);
void			make_letters(t_tetrimino **tetriminos, int len);
int				validate3(t_tetrimino *t, int len);
void			trim_all(t_tetrimino **t, int len);
void			free_map(t_tetrimino *tetrimino, int n);
void			backtracking(T_TET *the_map, T_TET *t, int len, int n);
void			fillit(t_tetrimino *t, int len);
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			error(void);

#endif
