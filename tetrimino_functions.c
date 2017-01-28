#include "fillitlib.h"
#include <unistd.h>
#include <stdio.h> // STERGE ASTA SAU IEI MINUSPATRUJDOI

void ft_putchar(char c)
{
  write(1, &c, 1);
}

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

int validate_tetrimino(t_tetrimino tetrimino)
{
  int i;
  int j;
  int nr;

  i = 0;
  printf("%i\n%i\n", tetrimino.lines, tetrimino.rows);
  while (i < tetrimino.lines)
  {
    j = 0;
    while (j < tetrimino.rows)
    {
      if (tetrimino.squares[i][j] == '#')
      {
        nr = get_neigbors(tetrimino, i, j, 'N');
        if (nr != 4)
          return (0);
        return (1);
      }
      j++;
    }
    i++;
  }
  return (1);
}
