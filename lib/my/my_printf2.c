/*
** EPITECH PROJECT, 2021
** my_printf2.c
** File description:
** printf2 proto
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"
#include <stdlib.h>

char *convert_base_up(unsigned int nb, int base, int token)
{
    char *new_nb = malloc(nb * sizeof(char) + 1);
    char *letter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

int is_printable(char c)
{
    if (!((c >= 0 && c <= 32) || c >= 127))
        return 1;
    return 0;
}

int is_letter(char c)
{
    if (c == '+' || c == '%' || c == '#' || c == '0' || c == ' ')
        return 1;
    if (!(c >= 'a' && c <= 'z')) {
        if (!(c >= 'A' && c <= 'Z'))
            return 0;
    }
    return 1;
}

void non_printable(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_printable(str[i]) == 1)
            my_putchar(str[i]);
        else
            octal_show(str[i]);
    }
}
