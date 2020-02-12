/*
** EPITECH PROJECT, 2020
** malloc_table
** File description:
** Malloc game table
*/

#include "../matchstick.h"

char **malloc_table(int n)
{
    char **table;

    table = malloc(sizeof(char *) * (n + 1));
    for (int a = 0; a < n; a++) {
        table[a] = malloc(sizeof(char) * (2 * n));
        for (int b = 0; b < ((2 * n) - 1); b++) {
            table[a][b] = ' ';
            table[a][(2 * n) - 1] = '\0';
        }
    }
    table[n] = NULL;
    return (table);
}

void free_tab(char **table)
{
    for (int i = 0; table[i] != NULL; i++) {
        free(table[i]);
    }
    free(table);
}
