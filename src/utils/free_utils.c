/*
** EPITECH PROJECT, 2022
** free_utils.c
** File description:
** free_utils
*/

#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

void free_all_arg(char ***array)
{
    for (int i = 0; array[i] != NULL; i++)
        free_array(array[i]);
    free(array);
}

void free_all(stock_t *stock)
{
    if (stock->new_env != NULL)
        free_array(stock->new_env);
    if (stock->id_arg == 1)
        free_all_arg(stock->arg);
    if (stock->path != NULL)
        free_array(stock->path);
    if (stock->home != NULL)
        free(stock->home);
    if (stock->prompt != NULL)
        free(stock->prompt);
    free(stock->buff);
    free(stock);
}
