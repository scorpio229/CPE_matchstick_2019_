/*
** EPITECH PROJECT, 2020
** nb_match
** File description:
** Return number of matches on one line
*/

#include "../matchstick.h"

int nb_match(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '|')
            count++;
    return (count);
}

int tab_nb_match(char **table)
{
    int count = 0;

    for (int i = 0; table[i] != NULL; i++)
        count += nb_match(table[i]);
    return (count);
}
