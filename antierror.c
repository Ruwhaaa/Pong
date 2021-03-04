/*
** EPITECH PROJECT, 2017
** Mathematics - OCLOO
** File description:
** 101pong - antierrror.c
*/

#include "include/my.h"

int	verif_argv(int y, int i, char **argv)
{
	int lock = 0;

	while (argv[y][i] != '\0') {
		if (argv[y][i] < '0' || argv[y][i] > '9') {
			if (argv[y][i] == '.' && (argv[y][i - 1]
			>= '0' && argv[y][i - 1] <= '9') && (argv[y][i + 1]
			>= '0' && argv[y][i + 1] <= '9') && lock != 1) {
				lock = 1;
			} else
				return (84);
		}
		i = i + 1;
	}
	return (0);
}

int	anti_argnull(char **argv)
{
	int i = 1;

	while (i != 7 + 1) {
		if (my_strlen(argv[i]) == 0)
			return (84);
		i = i + 1;
	}
	return (0);
}

int	antierror(int argc, char **argv)
{
	int i = 0;
	int y = 1;

 	if (argc != 8 || anti_argnull(argv) == 84)
		return (84);
	while (argc > 1) {
		if (argv[y][0] == '-')
			i = 1;
		if(verif_argv(y, i, argv) == 84)
			return (84);
		i = 0;
		y = y + 1;
		argc = argc - 1;
	}
	return (0);
}
