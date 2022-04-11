/*
** EPITECH PROJECT, 2022
** utils2.c
** File description:
** utils2
*/

#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

void check_memset(char *buff)
{
    if (buff[my_strlen(buff) - 1] == '\n')
        my_memset(buff, '\0', my_strlen(buff) - 1);
}

char *get_home(char **new_env)
{
    char *home = NULL;
    int parenthese = 0;
    int index = 0;

    for (int i = 0; new_env[i] != NULL; i++) {
        if (strcmp_start(new_env[i], "PWD=") == 1)
            home = my_strdup(new_env[i] + 4);
    }
    for (; parenthese < 2; index++) {
        if (home[index + 1] == '/')
            parenthese++;
    }
    my_memset(home, '\0', index);
    return home;
}

int index_character(char *str, char c, int nb)
{
    int count = 0;
    int i = 0;

    for (; str[i] != '\0' && count != nb; i++) {
        if (str[i] == c)
            count++;
    }
    return i;
}

char **copy_array(char **env)
{
    int x = 0;
    int y = 0;
    char **array = malloc(sizeof(char *) * (my_arrlen(env) + 1));

    if (array == NULL)
        return NULL;
    for (int i = 0; env[i] != NULL; i++) {
        array[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
        if (array[i] == NULL)
            return NULL;
    }
    for (; env[x] != NULL; x++) {
        y = 0;
        for (; env[x][y] != '\0'; y++)
            array[x][y] = env[x][y];
        array[x][y] = '\0';
    }
    array[x] = NULL;
    return array;
}
