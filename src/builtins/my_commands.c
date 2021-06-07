/*
** EPITECH PROJECT, 2021
** commande
** File description:
** ms
*/

#include "my.h"

int my_commands(char *buff, env_t *shenv)
{
    if (my_strncmp(buff, "cd", 2) == 0) {
        my_cd(buff, shenv);
        return 0;
    }
    if (my_strncmp(buff, "env", 3) == 0) {
        print_env(shenv);
        return 0;
    }
    else
        return -1;
}
