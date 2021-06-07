/*
** EPITECH PROJECT, 2020
** strncmp
** File description:
** a
*/

int my_strncmp(char *s1, char *s2, int n)
{
    int a;

    a = 0;
    while (s1[a] == s2[a] && s1[a] && s2[a] && a < n)
        a++;
    if ((s1[a] == '\0' && s2[a] == '\0') || a == n)
        return 0;
    else if (s1[a] > s2[a])
        return 1;
    else
        return -1;
}
