/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils.c
*/

#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

int strcmp_start(char *env, char *str)
{
    int size = my_strlen(str);

    for (int i = 0; i < size; i++) {
        if (env[i] != str[i])
            return 0;
    }
    return 1;
}

int no_arg(char *buff, int n)
{
    for (int i = n; buff[i] != '\0'; i++) {
        if (buff[i] != ' ')
            return 0;
    }
    return 1;
}

int return_index(char *str, char c)
{
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            index = i;
    }
    index++;
    return index;
}

int my_arrlen(char **array)
{
    int x = 0;

    for (; array[x] != NULL; x++);
    return x;
}

int index_key(char **new_env, char *key)
{
    for (int i = 0; new_env[i] != NULL; i++) {
        if (strcmp_start(new_env[i], key) == 1)
            return i;
    }
    return -1;
}
