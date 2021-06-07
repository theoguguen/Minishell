/*
** EPITECH PROJECT, 2020
** My_strcat
** File description:
** Concatenates 2 strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 1;
    int lend = my_strlen(dest);
    int lens = my_strlen(src);
    char *res = malloc(sizeof(char) * (lend + lens + 4));

    res[0] = '/';
    while (dest[i] != '\0') {
        res[j] = dest[i];
        i++;
        j++;
    }
    res[j] = '/';
    j++;
    for (i = 0; src[i] != '\0'; i++) {
        res[j] = src[i];
        j++;
    }
    res[j] = '\0';
    return (res);
}

char *my_strncat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int lend = my_strlen(dest);
    int lens = my_strlen(src);
    char *res = malloc(sizeof(char) * (lend + lens));

    while (dest[i] != '\0') {
        res[j] = dest[i];
        i++;
        j++;
    }
    i = 0;
    while (src[i] != '\0') {
        res[j] = src[i];
        i++;
        j++;
    }
    return (res);
}