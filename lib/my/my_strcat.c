/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** f
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strcat(char *dest, char *src)
{
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);
    char *str = malloc(sizeof(char) * (size_dest + size_src + 1));
    int i = 0;

    for (int j = 0; dest[j] != '\0'; j++) {
        str[i] = dest[j];
        i++;
    }
    for (int j = 0; src[j] != '\0'; j++) {
        str[i] = src[j];
        i++;
    }
    str[i] = '\0';
    return str;
}
