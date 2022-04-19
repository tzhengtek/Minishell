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
        if (arg[index][i] == '>' || arg[index][i] == '<')
            return i + 1;
    }
    return 0;
}

static char *redirecion_flag_stick(char **arg, int index, int tmp, int value)
{
    char *file = NULL;

    if (arg[index][tmp + value - 1] == '\0') {
        file = my_strdup(arg[index + 1]);
        my_memset(arg[index], '\0', get_filename_pos(arg, index) - 1);
        arg[index + 1] = NULL;
    } else {
        file = my_strdup(arg[index] + tmp + value - 1);
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
        file = redirecion_flag_stick(arg, index, tmp, value);
    return file;
}

char *get_filename(char **arg, int index, int *state)
{
    int tmp = get_filename_pos(arg, index);

    *state = check_double_redirection(arg, index, tmp);
    return redirection_condition(ABS(*state), arg, index, tmp);
}
