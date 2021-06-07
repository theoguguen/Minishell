/*
** EPITECH PROJECT, 2021
** B-PSU-210-REN-2-1-minishell2-theo.guguen
** File description:
** change_oldpwd
*/

#include "my.h"

static int checkp(char *src, char *str)
{
    int i = 0;

    while (str[i] != 0){
        if (src[i] == str[i])
            i++;
        else
            return 84;
    }
    return 0;
}

void change_oldpwd(env_t *shenv, char *pwd)
{
    int i = 0;
    char *str = "OLDPWD";

    while (shenv->shenv[i] != NULL){
        if (checkp(shenv->shenv[i], str) == 0)
            break;
        else
            i++;
    }
    shenv->env[i] = my_strncat("OLDPWD=", pwd);
}