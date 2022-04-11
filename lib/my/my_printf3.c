/*
** EPITECH PROJECT, 2021
** my_printf3.c
** File description:
** printf3
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"
#include <stdlib.h>

void octal_show(char str)
{
    if (str >= 0 && str <= 7) {
        my_putchar('\\');
        my_putchar('0');
        my_putchar('0');
        my_putstr(convert_base_up(str, 8, 0));
    }
    if (str <= 63 && str >= 8) {
        my_putchar('\\');
        my_putchar('0');
        my_putstr(convert_base_up(str, 8, 0));
    }
    if (str >= 127) {
        my_putchar('\\');
        my_putstr(convert_base_up(str, 8, 0));
    }
}

int print_sign_long(char *str, int i, long nb)
{
    if (nb >= 0)
        my_putchar('+');
    my_put_nbr_long(nb);
    return i + 2;
}

int print_sign_int(char *str, int i, int nb)
{
    if (str[i + 2] == 'd' || str[i + 2] == 'i') {
        if (nb >= 0)
            my_putchar('+');
        my_put_nbr(nb);
        return i + 1;
    }
}

int show_hash_hexa(int nb, char *str, int i)
{
    my_putchar('0');
    if (str[i + 2] == 'x') {
        my_putchar('x');
        my_putstr(convert_base_up(nb, 16, 0));
    } else {
        my_putchar('X');
        my_putstr(convert_base_up(nb, 16, 1));
    }
    return i + 1;
}

int show_hash_octal(int nb, int i)
{
    my_putchar('0');
    my_putstr(convert_base_up(nb, 8, 0));
    return i + 1;
}
