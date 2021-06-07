/*
** EPITECH PROJECT, 2021
** print
** File description:
** env
*/

#include "my.h"

void print_env(env_t *shenv)
{
    for (int i = 0; shenv->shenv[i] != NULL; i++) {
        my_putstr(shenv->shenv[i]);
        if (shenv->shenv[i] == shenv->env[i])
            my_putchar('\n');
    }
}