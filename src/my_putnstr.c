/*
** EPITECH PROJECT, 2021
** B-PSU-101-REN-1-1-minishell1-theo.guguen
** File description:
** my_putnstr
*/

#include "my.h"

void my_putnstr(char *str, int nb)
{
    int i = 0;

    while (i <= nb) {
        my_putchar(str[i]);
        i++;
    }
}