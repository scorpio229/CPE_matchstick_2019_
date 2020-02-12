/*
** EPITECH PROJECT, 2020
** view_table
** File description:
** View game board
*/

#include "../matchstick.h"

void view_table(int n, char **table)
{
    print_lim(n);
    for (int i = 0; table[i] != NULL; i++) {
        my_putchar('*');
        my_putstr(table[i]);
        my_putstr("*\n");
    }
    print_lim(n);
}
