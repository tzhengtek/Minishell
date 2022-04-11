/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my_printf.h"
#include <stdlib.h>

void flag_conversion(char *str, int i, va_list arg)
{
    if (str[i + 1] == 'S')
        non_printable(va_arg(arg, char *));
    if (str[i + 1] == 's')
        my_putstr(va_arg(arg, char *));
    if (str[i + 1] == 'i' || str[i + 1] == 'd')
        my_put_nbr(va_arg(arg, int));
    if (str[i + 1] == 'u')
        my_put_nbr_unsigned(va_arg(arg, int));
    if (str[i + 1] == 'c')
        my_putchar(va_arg(arg, int));
    if (str[i + 1] == 'p')
        show_pointer(va_arg(arg, int));
    if (str[i + 1] == 'e')
        print_error(va_arg(arg, char *));
    if (str[i + 1] == 'a')
        my_putarr(va_arg(arg, char **));
}

void flag(char *str, int i, va_list arg)
{
    flag_conversion(str, i, arg);
    if (str[i + 1] == 'o')
        my_putstr(convert_base_up(va_arg(arg, int), 8, 0));
    if (str[i + 1] == 'X')
        my_putstr(convert_base_up(va_arg(arg, int), 16, 1));
    if (str[i + 1] == 'x')
        my_putstr(convert_base_up(va_arg(arg, int), 16, 0));
    if (str[i + 1] == '%')
        my_putchar('%');
    if (str[i + 1] == 'b')
        my_putstr(convert_base_up(va_arg(arg, int), 2, 0));
}

int printf_show(char *str, int i, va_list arg)
{
    if (str[i + 1] == ' ') {
        if (str[i + 2] == 'd' || str[i + 2] == 'i')
            my_putchar(' ');
        printf_show(str, i + 1, arg);
        return i + 1;
    }
    flag(str, i, arg);
    if (str[i + 1] == 'l' && str[i + 2] == 'd') {
        my_put_nbr_long(va_arg(arg, long));
        return i + 1;
    }
    if (str[i + 1] == '#')
        i = hashtag(str, i, arg);
    if (str[i + 1] == '+' && (str[i + 2] == 'd' || str[i + 2] == 'i'))
        i = print_sign_int(str, i, va_arg(arg, int));
    if (str[i + 1] == '+' && str[i + 2] == 'l' && str[i + 3] == 'd')
        i = print_sign_long(str, i, va_arg(arg, long));
    if (str[i + 1] == '0')
        i = get_num_str(str, i + 2, arg);
    return i;
}

void my_printf(char *s, ...)
{
    va_list arg;
    va_start(arg, s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%' && is_letter(s[i + 1]) == 1) {
            i = printf_show(s, i, arg);
            i++;
        } else if (s[i] == '%' && s[i + 1] == '\0')
            i = my_strlen(s) - 1;
        else
            my_putchar(s[i]);
    }
    va_end(arg);
}
