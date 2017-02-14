#include "fillitlib.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

void error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int main(int argc, char **argv)
{
	char *buffer;
	int len;
	t_tetrimino *tetriminos;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(0);
	}
	buffer = (char*)malloc(sizeof(char) * 5000);
	len = read_file(argv, &buffer);
	if (!validate1(buffer, len))
		error();
	tetriminos = get_tetriminos(&buffer, &len);
	if (!validate2(tetriminos, len))
		error();
	if (!validate3(tetriminos, len))
		error();
	trim_all(&tetriminos, len);
	make_letters(&tetriminos, len);
	fillit(tetriminos, len);
	return (0);
}
