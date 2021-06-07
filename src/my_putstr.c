/*
** EPITECH PROJECT, 2020
** my_params_to_list.c
** File description:
**  creates a new list from the command line arguments
*/

#include "my.h"

void my_putstr(char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}