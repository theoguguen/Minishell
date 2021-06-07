/*
** EPITECH PROJECT, 2021
** fork
** File description:
** my
*/

#include "my.h"

void my_fork(char **env, char **tab, char *buff)
{
    int pid = fork();
    int status = 0;

    if (pid == -1)
        perror("fork");
    else if (pid > 0)
        waitpid(pid, &status, 0);
    else if (pid == 0)
        exec(env, tab, buff);
}