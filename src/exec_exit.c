/*
** EPITECH PROJECT, 2021
** B-PSU-210-REN-2-1-minishell2-theo.guguen
** File description:
** exec_exit
*/

#include "my.h"

void exec_exit(char **buff)
{
    my_putstr(buff[0]);
    my_putstr(": Command not found.\n");
    exit(0);
}