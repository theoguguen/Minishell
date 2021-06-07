/*
** EPITECH PROJECT, 2021
** home
** File description:
** get
*/

#include "my.h"

static int check(char *src, char *str)
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

static char *tempcpy(char *temp)
{
    int i = 5;
    int j = 0;
    char *home = malloc(sizeof(char) * my_strlen(temp));

    while (temp[i] != '\0'){
        home[j] = temp[i];
        j++;
        i++;
    }
    home[j] = '\0';
    return home;
}

void get_home(env_t *shenv)
{
    int i = 0;
    char *str = "HOME";
    char *temp = NULL;
    char *home;

    while (shenv->shenv[i] != NULL) {
        if (check(shenv->shenv[i], str) == 0) {
            temp = shenv->shenv[i];
            break;
        }
        else
            i++;
    }
    i = 0;
    home = tempcpy(temp);
    shenv->home = home;
}
