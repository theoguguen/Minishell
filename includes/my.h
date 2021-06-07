/*
** EPITECH PROJECT, 2021
** B-PSU-101-REN-1-1-minishell1-theo.guguen
** File description:
** my
*/

#include <stdarg.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>
#include <stddef.h>
#include <stdbool.h>

#ifndef MY_H_
#define MY_H_

typedef struct env_s {
    char **shenv;
    char *pwd;
    char *path;
    char *home;
    char *oldpwd;
    char **env;
}env_t;

int my_getnbr(char *str);

void my_putstr(char *str);

void my_putchar(char c);

char *my_strcpy(char *dest, char *src);

int my_strlen(char const *str);

char **char_2d(char *buff, char arg[100][100]);

void print_env(env_t *shenv);

int my_ls(char *pathname);

int my_printf(const char *src, ...);

void get_pwd();

int my_strcmp(char *s1, char *s2);

int my_cd(char *path, env_t *shenv);

void get_home(env_t *shenv);

char *my_strcat(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char **my_str_to_wordtab(char *str);

char **my_path_to_tab(char *str);

char **exec(char **env, char **tab, char *command);

int my_strncmp(char *s1, char *s2, int n);

int my_commands(char *buff, env_t *shenv);

void my_fork(char **env, char **tab, char *buff);

void prompt(env_t *shenv);

void get_pwd(env_t *shenv);

void my_putnstr(char *str, int nb);

void my_binary(char *buffer, char **env);

int my_setenv(env_t *shenv, char *buff);

char *my_strncat(char *dest, char const *src);

void my_unsetenv(env_t *shenv, char *buff);

void get_old(env_t *shenv);

void change_oldpwd(env_t *shenv, char *pwd);

void exec_exit(char **buff);

int check_pipe(char **tab, env_t *shenv);

int check_redirect(char **buff);

void my_redirect(char *file, char *buff, char **env, char *fpath);

char *get_file(char *command);

#endif
