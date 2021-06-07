/*
** EPITECH PROJECT, 2021
** B-PSU-101-REN-1-1-minishell1-theo.guguen
** File description:
** my_cd
*/

#include "my.h"

static int my_home(env_t *shenv, int len)
{
    if (len == 3){
        chdir(shenv->home);
        change_oldpwd(shenv, shenv->pwd);
        shenv->pwd = "/home";
        return 0;
    }
    return 1;
}

static int my_old(env_t *shenv, int len, char *path)
{
    if (len > 2 && path[3] == '-') {
        change_oldpwd(shenv, shenv->pwd);
        chdir(shenv->oldpwd);
        return 0;
    }
    return 1;
}

static void check_chdir(char *str)
{
    if (chdir(str) == -1){
        my_putstr(str);
        my_putstr(": ");
        my_putstr(strerror(errno));
        my_putstr(".\n");
    }
}

static int normal_cd(env_t *shenv, int len, char *path)
{
    int count = 0;
    int j = 3;
    char *str = malloc(sizeof(char) * (len + 1));

    if (len > 2 && path[2] == ' '){
        while (path[j] != '\n'){
            str[count] = path[j];
            j++;
            count++;
        }
        change_oldpwd(shenv, shenv->pwd);
        check_chdir(str);
        return 0;
    }
    else {
        my_putnstr(path, (len - 2));
        my_putstr(": Command not found.\n");
        return 84;
    }
    return 1;
}

int my_cd(char *path, env_t *shenv)
{
    int len = my_strlen(path);

    get_home(shenv);
    get_pwd(shenv);
    get_old(shenv);

    if (my_home(shenv, len) == 0)
        return 0;
    else if (my_old(shenv, len, path) == 0)
        return 0;
    else if (normal_cd(shenv, len, path) == 84)
        return 84;
    return 0;
}