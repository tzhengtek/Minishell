/*
** EPITECH PROJECT, 2021
** my_memset.c
** File description:
** my_memset
*/

int my_strlen(char const *str);

char *my_memset(char *str, char c, int n)
{
    for (int i = my_strlen(str); i > n; i--)
        str[i - 1] = c;
    return str;
}
