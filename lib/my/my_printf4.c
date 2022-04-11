/*
** EPITECH PROJECT, 2021
** printf4.c
** File description:
** printf4
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"

int hashtag(char *str, int i, va_list arg)
{
    if (str[i + 1] == '#' && (str[i + 2] == 'x' || str[i + 2] == 'X'))
        i = show_hash_hexa(va_arg(arg, int), str, i);
    if (str[i + 1] == '#' && str[i + 2] == 'o')
        i = show_hash_octal(va_arg(arg, int), i);
    if (str[i + 1] == '#' && (str[i + 2] == 'i' || str[i + 2] == 'd')) {
        my_put_nbr(va_arg(arg, int));
        return i + 1;
    }
    return i;
}

void show_zero(int nb, char *str)
{
    for (int i = 0; i < nb - my_strlen(str); i++)
        my_putchar('0');
    my_putstr(str);
}

void special_flag(char *str, int i, int nb_char, va_list arg)
{
    if (str[i] == 'x')
        show_zero(nb_char, convert_base_up(va_arg(arg, int), 16, 0));
    if (str[i] == 'X')
        show_zero(nb_char, convert_base_up(va_arg(arg, int), 16, 1));
    if (str[i] == 'd' || str[i] == 'i')
        show_zero(nb_char, convert_base_up(va_arg(arg, int), 10, 0));
    if (str[i] == 'o')
        show_zero(nb_char, convert_base_up(va_arg(arg, int), 8, 0));
    if (str[i] == 'u')
        show_zero(nb_char, convert_base_up(va_arg(arg, unsigned int), 10, 0));
}

int get_num_str(char *str, int i, va_list arg)
{
    char *new_str = malloc(my_strlen(str) * sizeof(char) + 1);
    int j = 0;
    int nb_char = 0;
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        new_str[j] = str[i];
        j++;
    }
    new_str[j] = '\0';
    nb_char = my_getnbr(new_str);
    special_flag(str, i, nb_char, arg);
    free(new_str);
    return i - 1;
}

void show_pointer(int nb)
{
    my_putstr("0x");
    my_putstr(convert_base_up(nb, 16, 0));
}
