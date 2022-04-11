/*
** EPITECH PROJECT, 2022
** my_putarr.c
** File description:
** my_putarr
*/

#include <stddef.h>

void my_putstr(char *str);
void my_putchar(char c);

void my_putarr(char **array)
{
    int i = 0;

    for (; array[i + 1] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
    my_putstr(array[i]);
}
