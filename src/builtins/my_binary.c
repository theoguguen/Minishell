/*
** EPITECH PROJECT, 2021
** B-PSU-210-REN-2-1-minishell2-theo.guguen
** File description:
** my_binary
*/

#include "my.h"

static void my_exec(char *binary, char *buffer, char *arg[], char **env)
{
    if (access(binary, X_OK) == -1) {
        my_putstr(buffer);
        my_putstr(": Permission denied.\n");
        exit(0);
    }
    else
        execve(binary, arg, env);
}

void my_binary(char *buffer, char **env)
{
    size_t j = 0;
    char *binary = malloc(sizeof(char) * my_strlen(buffer) + 1);
    char *arg[3] = {binary, 0, 0};
    pid_t pid;
    int status;

    for (size_t i = 2; buffer[i] != '\n'; i++) {
        binary[j] = buffer[i];
        j++;
    }
    pid = fork();
    if (pid == -1)
        perror("fork");
    if (pid == 0)
        my_exec(binary, buffer, arg, env);
    if (pid < 0)
        waitpid(pid, &status, 0);
}