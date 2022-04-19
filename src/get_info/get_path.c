/*
** EPITECH PROJECT, 2022
** str_to_array2.c
** File description:
** str_to_array
*/

#include <stdlib.h>
#include "my_printf.h"
#include "proto.h"

char **get_path_argument(char *env)
{
    char **array = str_to_array(env + 5, ":\n");
    char *save = NULL;

    for (int i = 0; array[i] != NULL; i++) {
        save = my_strcat(array[i], "/");
        free(array[i]);
        array[i] = my_strdup(save);
        free(save);
    }
    return array;
}

char **get_path(char **env)
{
    char **array = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        if (strcmp_start(env[i], "PATH=") == 1)
            array = get_path_argument(env[i]);
    }
    return array;
}
