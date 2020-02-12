/*
** EPITECH PROJECT, 2020
** player_turn
** File description:
** Make player modification
*/

#include "../matchstick.h"

char *player_input(void)
{
    int rd;
    size_t size = 4;
    char *str;

    str = malloc(sizeof(char) * size);
    rd = getline (&str, &size, stdin);
    if (rd == -1)
        return (NULL);
    else {
        str[rd - 1] = '\0';
        return (str);
    }
}

int valid_input(char *str)
{
    if (my_strlen(str) == 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (-1);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (-1);
        } else
            continue;
    }
    return (0);
}

int valid_value(int input, int max)
{
    if (input == 0 || input > max) {
        my_printf("Error: this line is out of range\n");
        return (-1);
    }
    return (0);
}

int valid_matches(int input, int max, char *line)
{
    if (input == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return (-1);
    }
    if (input > max) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
        max);
        return (-1);
    }
    if (input > nb_match(line)) {
        my_printf("Error: not enough matches on this line\n");
        return (-1);
    }
    return (0);
}

int player_turn(char **table, info_t game)
{
    my_printf("Line: ");
    char *line_in = player_input();
    if (line_in == NULL)
        return (-1);
    if (valid_input(line_in) == -1)
        return (-2);
    int line = my_getnbr(line_in);
    if (valid_value(line, game.max_l) == -1)
        return (-2);
    my_printf ("Matches: ");
    char *match_in = player_input();
    if (match_in == NULL)
        return (-1);
    if (valid_input(match_in) == -1)
        return (-2);
    int match = my_getnbr(match_in);
    if (valid_matches(match, game.max_m, table[line - 1]) == -1)
        return (-2);
    rm_match(table[line - 1], match);
    my_printf("Player removed %d match(es) from line %d\n", match, line);
    return (0);
}
