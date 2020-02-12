/*
** EPITECH PROJECT, 2020
** game_loop
** File description:
** Matchstick game loop
*/

#include "../matchstick.h"

int game_loop(char **table, info_t game)
{
    int i = 0;

    while (tab_nb_match(table) != 0) {
        my_printf("\nYour turn:\n"); here:
        i = player_turn(table, game);
        if (i == -2)
            goto here;
        if (i == -1)
            return (0);
        view_table(game.max_l, table);
        if (tab_nb_match(table) == 0) {
            my_printf("You lost, too bad...\n");
            return (2);
        }
        ai_turn(table, game);
        view_table(game.max_l, table);
        if (tab_nb_match(table) == 0) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return (1);
        }
    }
}
