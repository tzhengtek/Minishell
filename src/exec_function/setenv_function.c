/*
** EPITECH PROJECT, 2022
** setenv.c
** File description:
** setenv
*/

#include <stdlib.h>
#include "my_printf.h"
#include "proto.h"

static char **my_setenv(stock_t *stock, char **arg)
{
    if (index_key(stock->new_env, arg[1]) == -1)
        return create_key(stock, arg);
    if (index_key(stock->new_env, arg[1]) != -1)
        return modify_key(stock, arg);
    return NULL;
}

int check_setenv(stock_t *stock, char **arg)
{
    if (my_arrlen(arg) > 3 &&
    my_strcmp(arg[0], "setenv") == 0) {
        print_error("setenv: Too many arguments.\n");
        return 1;
    }
    if (my_strcmp(arg[0], "setenv") == 0) {
        if (arg[1] == NULL) {
            print_env(stock->new_env);
            return 1;
        }
        if (check_alaphanumeric(arg[1]) == 0)
            return 1;
        if (my_arrlen(arg) > 1) {
            stock->new_env = my_setenv(stock, arg);
            return 1;
        }
    }
    return 0;
}
