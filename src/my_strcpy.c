/*
** EPITECH PROJECT, 2020
** strcpy
** File description:
** a
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (i < my_strlen(src) + 1){
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
