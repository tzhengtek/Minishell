/*
** EPITECH PROJECT, 2022
** array.c
** File description:
** arrayt
*/

#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

int check_key(char **env, char *key)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (strcmp_start(env[i], key) == 1)
            return 1;
    }
    return 0;
}

int count_key_cond(char **new_env, char *arg, int count)
{
    for (int j = 0; new_env[j] != NULL; j++) {
        if (strcmp_start(new_env[j], arg) == 1)
            count++;
    }
    return count;
}

int count_key(stock_t *stock, char **arg)
{
    int count = 0;

    for (int i = 1; arg[i] != NULL; i++)
        count = count_key_cond(stock->new_env, arg[i], count);
    return count;
}

int check_same_key(char *env, int index, char **new_env, char **arg)
{
    for (int j = 1; arg[j] != NULL; j++) {
        if (strcmp_start(env, arg[j]) == 1)
            return index;
    }
    for (int j = 1; arg[j] != NULL; j++) {
        new_env[index] = my_strdup(env);
        index++;
        return index;
    }
    return index;
}
