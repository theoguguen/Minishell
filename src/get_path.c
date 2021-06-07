/*
** EPITECH PROJECT, 2021
** home
** File description:
** get
*/

#include "my.h"

static int checkp(char *src, char *str)
{
    int i = 0;

    while (str[i] != 0) {
        if (src[i] == str[i])
            i++;
        else
            return 84;
    }
    return 0;
}

static char *tempcpyp(char *temp)
{
    int i = 5;
    int j = 0;
    char *path = malloc(sizeof(char) * my_strlen(temp));

    while (temp[i] != '\0') {
        path[j] = temp[i];
        j++;
        i++;
    }
    path[j] = '\0';
    return path;
}

static char *get_var(char **env)
{
    int i = 0;
    char *str = "PATH";
    char *temp = NULL;
    char *path = NULL;

    while (env[i] != NULL) {
        if (checkp(env[i], str) == 0) {
            temp = env[i];
            break;
        }
        else
            i++;
    }
    path = tempcpyp(temp);
    return path;
}

static char *get_path_exec(char **tab, char **buff)
{
    int i = 0;
    char *path = NULL;
    char *u = "usr";
    char *b = "bin";
    char *ub = NULL;

    while (tab[i] != NULL) {
        if (my_strcmp(tab[i], u) == 0 && my_strcmp(tab[i + 1], b) == 0) {
            ub = my_strcat(tab[i], tab[i + 1]);
            path = my_strcat(ub, buff[0]);
            break;
        }
        else
            i++;
    }
    return path;
}

char **exec(char **env, char **buff, char *command)
{
    char *path = get_var(env);
    char **tab = my_path_to_tab(path);
    char *fpath = get_path_exec(tab, buff);
    char *filename = get_file(command);

    if (buff[0][0] == '.' && buff[0][1] == '/') {
        if (access(buff[0], X_OK) == -1)
            exec_exit(buff);
        else
            execve(buff[0], buff, env);
    }
    if (check_redirect(buff) == 0)
        my_redirect(filename, command, env, fpath);
    if (access(fpath, X_OK) == -1)
        exec_exit(buff);
    else
        execve(fpath, buff, env);
    return env;
}
