/*
** EPITECH PROJECT, 2022
** redirection_utils_filename.c
** File description:
** redireciton_utils_filename
*/

#include <stdlib.h>
#include "proto.h"

char *get_redirection_file(char **arg, int *state)
{
    int index = 0;

    if ((index = check_redirection(arg)) == -1)
        return NULL;
    return get_filename(arg, index, state);
}
