/*
** EPITECH PROJECT, 2022
** create_function.c
** File description:
** create_function
*/

#include <unistd.h>
#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

char **create_env(void)
{
    char **new_env = malloc(sizeof(char *) * 1);

    if (new_env == NULL)
        return NULL;
    new_env[0] = NULL;
    return new_env;
}

stock_t *create_stock(char **env)
{
    stock_t *stock = malloc(sizeof(stock_t));

    if (my_arrlen(env) == 0)
        env = create_env();
    stock->new_env = copy_array(env);
    stock->prompt = get_prompt();
    stock->path = get_path(stock->new_env);
    stock->home = get_home(stock->new_env);
    stock->pwd = NULL;
    stock->id_arg = 0;
    stock->id_cd = 0;
    stock->arg = NULL;
    stock->buff = NULL;
    return stock;
}
