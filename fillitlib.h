#ifndef FILLITLIB
# define FILLITLIB

typedef struct	tetrimino
{
  char **squares;
  int lines;
  int rows;
} t_tetrimino;

int read_file(char **argv, char **buffer);
int validate1(char *str, int len);
t_tetrimino *get_tetriminos(char **buffer, int *len);
int validate2(t_tetrimino *tetriminos, int len);
void print_tetrimino(t_tetrimino tetrimino);
int validate_tetrimino(t_tetrimino tetrimino);

#endif
