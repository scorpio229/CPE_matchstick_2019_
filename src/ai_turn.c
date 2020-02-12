/*
** EPITECH PROJECT, 2020
** ai_turn
** File description:
** Define ai behaviour
*/

#include "../matchstick.h"

int good_line(char **table, int matches)
{
    int line_match = 0;

    for (int i = 0; table[i] != NULL; i++) {
        line_match = nb_match(table[i]);
        if (line_match >= matches)
            return (i + 1);
    }
    return (-1);
}

info_t search_good_line(char **table, int match)
{
    info_t good = {-1, match};

    while (good.max_l == -1) {
        good.max_l = good_line(table, good.max_m);
        if (good.max_l == -1) {
            good.max_m--;
            continue;
        } else
            return (good);
    }
}

int apply_search(char **table, int match)
{
    info_t good = {0, 0};

    good = search_good_line(table, match);
    rm_match(table[good.max_l - 1], good.max_m);
    my_printf("AI removed %d match(es) from line %d\n",
    good.max_m, good.max_l);
    return (0);
}

int ai_turn(char **table, info_t game)
{
    my_printf("\nAI's turn...\n");
    int i = tab_nb_match(table);

    if (i > game.max_m) {
        int rm = (i % (game.max_m + 1)) - 1;
        if (rm < 0) {
            apply_search(table, game.max_m + 1 + rm);
        } else if (rm == 0) {
            apply_search(table, 1);
        } else {
            apply_search(table, rm);
        }
    } else if (i <= game.max_m) {
        if (i == game.max_m) {
            apply_search(table, game.max_m - 1);
        } else if (i == 1) {
            apply_search(table, 1);
        } else {
            apply_search(table, i - 1);
        }
    } return (0);
}
