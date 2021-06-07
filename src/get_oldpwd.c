/*
** EPITECH PROJECT, 2021
** B-PSU-210-REN-2-1-minishell2-theo.guguen
** File description:
** get_oldpwd
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

static char *tempcpyp(char *temp)
{
    int i = 7;
    int j = 0;
    char *path = malloc(sizeof(char) * my_strlen(temp));

    while (temp[i] != '\0'){
        path[j] = temp[i];
        j++;
        i++;
    }
    path[j] = '\0';
    return path;
}

void get_old(env_t *shenv)
{
    int i = 0;
    char *str = "OLDPWD";
    char *temp = NULL;
    char *path = NULL;

    while (shenv->shenv[i] != NULL){
        if (checkp(shenv->shenv[i], str) == 0){
            temp = shenv->shenv[i];
            break;
        }
        else
            i++;
    }
    path = tempcpyp(temp);
    shenv->oldpwd = path;
}
