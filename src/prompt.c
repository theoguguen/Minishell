/*
** EPITECH PROJECT, 2021
** prompt
** File description:
** my
*/

#include "my.h"

void prompt(env_t *shenv)
{
    char *buff = NULL;
    char **tab;
    size_t s = 0;

    while (true) {
        my_putstr("$> ");
        if (getline(&buff, &s, stdin) == -1) {
            my_putstr("exit\n");
            break;
        }
        tab = my_str_to_wordtab(buff);
        if (my_strcmp(buff, "exit\n") == 0) {
            my_putstr("exit\n");
            break;
        }
        if (my_commands(buff, shenv) == 0)
            continue;
        else
            my_fork(shenv->shenv, tab, buff);
    }
}