/*
** EPITECH PROJECT, 2021
** convert_base.c
** File description:
** convert_base
*/

#include <stdlib.h>

char *my_revstr(char *str);

char *convert_base_up(unsigned int nb, int base, int token)
{
    char *new_nb = malloc(nb * sizeof(char) + 1);
    const char *letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;

    if (token == 0)
        letter = "abcdefghijklmnopqrstuvwxyz";
    for (; nb % base != nb; i++) {
        if (nb % base > 9)
            new_nb[i] = letter[nb % base % 10];
        else
            new_nb[i] = nb % base + '0';
        nb /= base;
    }
    if (nb % base > 9)
        new_nb[i] = letter[nb % base % 10];
    else
        new_nb[i] = nb % base + '0';
    new_nb[i + 1] = '\0';
    return my_revstr(new_nb);
}
