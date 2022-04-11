/*
** EPITECH PROJECT, 2022
** check_argument.c
** File description:
** check_argument
*/

#include <stdlib.h>
#include "my_printf.h"
#include "proto.h"

char ***check_multiple_arg(char *buff)
{
    char **get_arg = str_to_array(buff, ";");
    int count = my_arrlen(get_arg);
    char ***arg = malloc(sizeof(char **) * (count + 1));

    for (int i = 0; i < count; i++)
        arg[i] = str_to_array(get_arg[i], " \t\n");
    arg[count] = NULL;
    free_array(get_arg);
    return arg;
}
