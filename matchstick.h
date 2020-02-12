/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** Project header file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct game {
    int max_l;
    int max_m;
} info_t;

void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char *str);
int my_printf(char *str, ...);
void view_table(int n, char **table);
int my_getnbr(char const *str);
char **malloc_table(int n);
void print_lim(int n);
void put_match(int n, char **table);
void rm_match(char *line, int nb);
int nb_match(char *str);
int tab_nb_match(char **table);
int player_turn(char **table, info_t game);
int game_loop(char **table, info_t game);
int ai_turn(char **table, info_t game);
void free_tab(char **table);
