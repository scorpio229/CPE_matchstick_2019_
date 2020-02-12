/*
** EPITECH PROJECT, 2020
** put_match
** File description:
** Put matches on game board
*/

#include "../matchstick.h"

void put_match(int n, char **table)
{
    int count1 = ((2 * n) - 1) / 2;
    int count2 = count1;

    for (int a = 0; table[a] != NULL; a++, count1--, count2++) {
        for (int i = a; table[i] != NULL; i++) {
            table[i][count1] = '|';
            table[i][count2] = '|';
        }
    }
}
