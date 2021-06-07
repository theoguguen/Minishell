/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Counts and returns nb of characters in a str
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
