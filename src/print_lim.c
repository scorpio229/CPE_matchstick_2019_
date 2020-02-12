/*
** EPITECH PROJECT, 2020
** print_lim
** File description:
** Print game board limit
*/

#include "../matchstick.h"

void print_lim(int n)
{
    int i = 0;
    char *lim = malloc(sizeof(char) * ((2 * n) + 3));

    for (i = 0; i < (2 * n) + 1; i++)
        lim[i] = '*';
    lim[2 * n + 1] = '\n';
    lim[(2 * n) + 2] = '\0';
    my_putstr(lim);
    free(lim);
}
