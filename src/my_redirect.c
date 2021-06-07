/*
** EPITECH PROJECT, 2021
** B-PSU-210-REN-2-1-minishell2-theo.guguen
** File description:
** my_redirect
*/

#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int check_redirect(char **buff)
{
    for (size_t i = 0; buff[i] != NULL; i++)
        for (size_t j = 0; buff[i][j]; j++)
            if (buff[i][j] == '>')
                return 0;
    return 1;
}

char *getcommand(char *buff)
{
    char *comm = malloc(sizeof(char) * 10);
    size_t c = 0;

    for (size_t i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '>')
            return comm;
        comm[c] = buff[i];
        c++;
        }
    return comm;
}

void my_redirect(char *file, char *buff, char **env, char *fpath)
{
    int redfd = open(file, O_CREAT | O_TRUNC | O_WRONLY);
    char *command = getcommand(buff);
    char **com = my_str_to_wordtab(command);

    dup2(redfd, STDOUT_FILENO);
    dup2(redfd, STDIN_FILENO);
    close(redfd);
    execve(fpath, com, env);
}

char *get_file(char *command)
{
    size_t i = 0;
    size_t j = 0;
    char *filename = malloc(sizeof(char) * 10);

    while (command[i]) {
        if (command[i] == '>') {
            i++;
            break;
        }
        i++;
    }
    while (command[i]) {
        if ((command[i] >= 65 && command[i] <= 90) ||
        (command[i] >= 97 && command[i] <= 122) || command[i] == '.') {
            filename[j] = command[i];
            i++;
            j++;
        } else
            i++;
    }
    return filename;
}