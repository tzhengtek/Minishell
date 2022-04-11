/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** strdup
*/

#include <stdlib.h>

#include <stdio.h>

int my_strlen(char const *str);

void my_putstr(char *str);

char *my_strdup(char const *src)
{
    int size = my_strlen(src);
    char *new_str;
    int i;

    new_str = malloc(sizeof(char) * (size + 1));
    for (i = 0; src[i] != '\0'; i++)
        new_str[i] = src[i];
    new_str[i] = '\0';
    return new_str;
}
