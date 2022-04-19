/*
** EPITECH PROJECT, 2022
** create_key.c
** File description:
** craete_key
*/

#include <stdlib.h>
#include "my_printf.h"
#include "proto.h"

char **create_key(stock_t *stock, char **arg)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * (my_arrlen(stock->new_env) + 2));
    char *save = NULL;

    if (new_env == NULL)
        return NULL;
    for (; stock->new_env[i] != NULL; i++)
        new_env[i] = my_strdup(stock->new_env[i]);
    new_env[i] = my_strcat(arg[1], "=");
    if (my_arrlen(arg) == 3) {
        save = my_strdup(new_env[i]);
        free(new_env[i]);
        new_env[i] = my_strcat(save, arg[2]);
    }
    new_env[i + 1] = NULL;
    free_array(stock->new_env);
    free(save);
    return new_env;
}

void add_key_array(stock_t *stock, char *key, char *value)
{
    int i = 0;
    int count = my_arrlen(stock->new_env) + 2;
    char **copy = copy_array(stock->new_env);

    free_array(stock->new_env);
    stock->new_env = malloc(sizeof(char *) * count);
    for (; copy[i] != NULL; i++)
        stock->new_env[i] = my_strdup(copy[i]);
    stock->new_env[i] = my_strcat(key, value);
    stock->new_env[i + 1] = NULL;
}

char **modify_key(stock_t *stock, char **arg)
{
    char *the_env = NULL;
    char *save = NULL;
    int index = 0;

    if (my_arrlen(arg) == 2)
        stock->new_env[index_key(stock->new_env, arg[1])] =
        my_strcat(arg[1], "=");
    else {
        save = my_strcat(arg[1], "=");
        the_env = my_strcat(save, arg[2]);
        index = index_key(stock->new_env, arg[1]);
        free(stock->new_env[index]);
        stock->new_env[index] = my_strdup(the_env);
        free(save);
        free(the_env);
    }
    return stock->new_env;
}
