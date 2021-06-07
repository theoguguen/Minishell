/*
** EPITECH PROJECT, 2021
** B-CPE-110-REN-1-1-BSQ-theo.guguen
** File description:
** load2d
*/

#include "my.h"

static int is_space(char c)
{
    if (c <= ' ')
        return 0;
    return 1;
}

static int word_count(char *str)
{
    int i = 0;
    int counter = 0;

    while (str != NULL && str[i]){
        if (is_space(str[i]) == 1 && is_space(str[i + 1]) == 0)
            counter = counter + 1;
        i++;
    }
    return counter;
}

char **my_str_to_wordtab(char *str)
{
    int j = 0;
    int i = 0;
    char **tab;
    int len = 0;

    tab = malloc((word_count(str) + 1) * sizeof(char *));
    while (str != NULL && str[i]){
        if (is_space(str[i]))
            len = len + 1;
        if (is_space(str[i]) == 1 && is_space(str[i + 1]) == 0){
            tab[j] = malloc(len + 1);
            my_strncpy(tab[j], &str[i - len + 1], len);
            len = 0;
            j++;
        }
        i++;
    }
    tab[j] = NULL;
    return tab;
}
