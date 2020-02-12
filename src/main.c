/*
** EPITECH PROJECT, 2020
** main
** File description:
** Project main
*/

#include "../matchstick.h"

int view_error(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (-1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    int n = 0;
    int max_m = 0;
    int ret = 0;
    char **table = NULL;

    if (ac == 3) {
        if (view_error(ac, av) == -1)
            return (84);
        n = my_getnbr(av[1]);
        max_m = my_getnbr(av[2]);
        if (n <= 0 || max_m <= 0)
            return (84);
        table = malloc_table(n);
        put_match(n, table);
        view_table(n, table);
        info_t game = {n, max_m};
        ret = game_loop(table, game);
        free_tab(table);
        return (ret);
    } else
        return (84);
}
