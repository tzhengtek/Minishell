/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** task13
*/

#include <stdlib.h>

int my_str_isnum(char const *str);

int my_str_isnum(char const *str)
{
    int nb_number = 0;
    int i;
    if (str == NULL)
        return 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 48 && str[i] <= 57 || str[i] == '-'))
            nb_number++;
    }
    if (nb_number == 0)
        return 1;
    else
        return 0;
}
