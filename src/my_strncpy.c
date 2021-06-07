/*
** EPITECH PROJECT, 2020
** strncpy
** File description:
** a
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int j = 0;

    while (j < n){
        dest[j] = src[j];
        j++;
    }
    while (j > n){
        dest[j] = '\0';
        j++;
    }
    return (dest);
}
