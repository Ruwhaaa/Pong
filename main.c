/*
** EPITECH PROJECT, 2017
** Mathematics - OCLOO
** File description:
** 101pong - fichier main
*/

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

void	incidence_angle(double *tab)
{
	double angle;
	double vx = tab[3] - tab[0];
	double vy = tab[4] - tab[1];
	double vz = tab[5] - tab[2];

	printf("The incidence angle is :\n");
	if (vz == 0 && tab[5] != 0) {
		printf("The ball won't reach the bat.\n");
		return;
	}
	if ((-tab[5] / vz) < 0) {
		printf("The ball won't reach the bat.\n");
		return;
	}
	angle = 90 - 180 / M_PI * acos(vz / sqrt(pow(vx, 2) +
		pow(vy, 2) + pow(vz, 2)));
	if (angle < 0)
		angle = angle * -1;
	printf("%.2f degrees\n", angle);
	return;
}

void	ball_coordinates(double *tab)
{
	double px = tab[3] + (tab[6] * (tab[3] - tab[0]));
	double py = tab[4] + (tab[6] * (tab[4] - tab[1]));
	double pz = tab[5] + (tab[6] * (tab[5] - tab[2]));

	printf("At time t+%.0f, ball coordinates will be :\n", tab[6]);
	printf("(%.2f;%.2f;%.2f)\n", px, py, pz);
	return;
}

void	speed_vector(double *tab)
{
	double vx = tab[3] - tab[0];
	double vy = tab[4] - tab[1];
	double vz = tab[5] - tab[2];

	printf("The speed vector coordinates are :\n");
	printf("(%.2f;%.2f;%.2f)\n", vx, vy, vz);
	return;
}

int	main(int argc, char **argv)
{
	double tab[7];
	int i = 1;

	if (antierror(argc, argv) == 84) {
		write(2, "Error 84\n", 9);
		return (84);
	}
	while (i - 1 < 7) {
		tab[i - 1] = my_getnbr_comma(argv[i]);
		i = i + 1;
	}
	speed_vector(tab);
	ball_coordinates(tab);
	incidence_angle(tab);
	return (0);
}
