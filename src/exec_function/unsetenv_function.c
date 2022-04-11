/*
** EPITECH PROJECT, 2022
** unsetenv.c
** File description:
** unsetenv
*/

#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

static char **my_unsetenv(stock_t *stock, char **arg)
{
    int same = count_key(stock, arg);
    int index = 0;
    char **new_env =
    malloc(sizeof(char *) * ((my_arrlen(stock->new_env) - same) + 1));

    if (new_env == NULL)
        return NULL;
    for (int i = 0; stock->new_env[i] != NULL; i++)
        index = check_same_key(stock->new_env[i], index, new_env, arg);
    new_env[index] = NULL;
    free_array(stock->new_env);
    return new_env;
}

int check_unsetenv(stock_t *stock, char **arg)
{
    if (my_arrlen(arg) == 1 &&
        my_strcmp(arg[0], "unsetenv") == 0) {
        print_error("unsetenv: Too few arguments.\n");
        return 1;
    }
    if (my_strcmp(arg[0], "unsetenv") == 0) {
        stock->new_env = my_unsetenv(stock, arg);
        return 1;
    }
    return 0;
}
