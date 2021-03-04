/*
** EPITECH PROJECT, 2017
** Mathematics - OCLOO
** File description:
** 101pong - my_getnbr_comma.c
*/

#include <stdio.h>

int	posornot(char const *str)
{
	int i = 0;

	while (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-') {
			i = i + 1;
		}
	}
	return (i);
}

double	my_getnbr_comma(char const *str)
{
	int i = 0;
	double nb = 0;

	if (str == NULL)
		return (0);
	i = posornot(str);
	while (nb <= 2147483647 && str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10 + (str[i] - 48);
		i = i + 1;
	}
	if (str[i] == '.')
		while (nb <= 2147483647 && str[i + 1] >= '0' && str[i + 1] <= '9') {
			nb = nb * 0.1 + (str[i + 1] - 48);
			i = i + 1;
		}
	if (nb > 2147483647)
		return (0);
	if (posornot(str) % 2 != 0)
		return (-nb);
	return (nb);
}
