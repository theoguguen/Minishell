/*
** EPITECH PROJECT, 2021
** Minishell
** File description:
** a
*/

#include "my.h"

int main(int ac, __attribute__((unused))char **av, char **env)
{
    env_t *shenv = malloc(sizeof(env_t));

    shenv->shenv = env;
    shenv->env = env;
    if (ac != 1)
        return 84;
    prompt(shenv);
    free(shenv);
    return 0;
}
