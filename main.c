#include <stdlib.h>
#include <stdio.h>
#include "fillitlib.h"

int main(int argc, char **argv)
{
  char *buffer;
  int len;
  t_tetrimino *tetriminos;

  buffer = (char*)malloc(sizeof(char) * 5000);
  len = read_file(argv, &buffer);
  //TODO VALIDATION 1
  tetriminos = get_tetriminos(&buffer, &len);
  printf("%i\n", validate_tetrimino(tetriminos[1]));

  return 0;
}
