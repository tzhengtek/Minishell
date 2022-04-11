/*
** EPITECH PROJECT, 2022
** check_redirection_utils2.C
** File description:
** redirection_utils2.c
*/

#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

static int get_filename_pos(char **arg, int index)
{
    for (int i = 0; arg[index][i] != '\0'; i++) {
        if (arg[index][i] == '>')
            return i + 1;
    }
    return 0;
}

static char *redirecion_flag_stick(char **arg, int index, int tmp)
{
    char *file = NULL;

    if (arg[index][tmp] == '\0') {
        file = my_strdup(arg[index + 1]);
        my_memset(arg[index], '\0', get_filename_pos(arg, index) - 1);
        arg[index + 1] = NULL;
    } else {
        file = my_strdup(arg[index] + tmp);
        my_memset(arg[index], '\0', get_filename_pos(arg, index) - 1);
        if (my_strlen(arg[index]) == 0)
            arg[index] = NULL;
    }
    return file;
}

static char *redirection_flag_split(char **arg, int index)
{
    char *file = NULL;

    if (arg[index + 1] != NULL) {
        file = my_strdup(arg[index + 1]);
        arg[index] = NULL;
        arg[index + 1] = NULL;
    } else
        my_printf("%e\n", "Missing name for redirect.");
    return file;
}

static char *redirection_condition(int value, char **arg, int index, int tmp)
{
    char *file = NULL;

    if (my_strlen(arg[index]) == value)
        file = redirection_flag_split(arg, index);
    else if (my_strlen(arg[index]) != value)
        file = redirecion_flag_stick(arg, index, tmp);
    return file;
}

char *get_filename(char **arg, int index, int *state)
{
    int tmp = get_filename_pos(arg, index);

    if (check_double_redirection(arg, index, tmp) == 0)
        *state = 1;
    else
        *state = 2;
    return redirection_condition(*state, arg, index, tmp);
}
