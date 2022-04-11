/*
** EPITECH PROJECT, 2022
** utils3.
** File description:
** utils3
*/

#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

int is_alpha(char c)
{
    if (c == '_')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

int is_alphanumeric(char c)
{
    if (is_alpha(c) == 1 || (c >= '0' && c <= '9') || (c == '.'))
        return 1;
    return 0;
}

int check_alaphanumeric(char *str)
{
    if (is_alpha(str[0]) == 0) {
        print_error("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (is_alphanumeric(str[i]) == 0) {
            print_error("setenv: Variable name must ");
            print_error("contain alphanumeric characters.\n");
            return 0;
        }
    }
    return 1;
}
