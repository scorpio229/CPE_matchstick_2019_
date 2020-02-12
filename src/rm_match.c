/*
** EPITECH PROJECT, 2020
** rm_match
** File description:
** Remove matches from line
*/

#include "../matchstick.h"

void rm_match(char *line, int nb)
{
    int begin = my_strlen(line) - 1;

    while (line[begin] == ' ')
        begin--;
    for (int i = begin; nb != 0; i--, nb--)
        line[i] = ' ';
}
