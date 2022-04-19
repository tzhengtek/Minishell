/*
** EPITECH PROJECT, 2022
** exec_redirection.c
** File description:
** exec_redirection
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "proto.h"
#include "my_printf.h"

char **remove_index_array(char **arg, int index, int size)
{
    char **new_array = malloc(sizeof(char *) * size);
    int tmp = 0;

    for (int i = 0; arg[i] != NULL; i++) {
        if (i != index) {
            new_array[tmp] = my_strdup(arg[i]);
            tmp++;
        }
    }
    new_array[size - 1] = NULL;
    free_array(arg);
    return new_array;
}

int redirection_type_std(int state, char *file)
{
    if (state <= 2 && state > 0)
        return redirection_stdout(state, file);
    else if (state == -1)
        return redirection_stdin(file);
    else
        return double_redirection_stdin(file);
}

int redirection_cmd(char **file, char **arg)
{
    int state = 0;

    if ((*file = get_redirection_file(arg, &state)) == NULL)
        return 0;
    if (redirection_type_std(state, *file) == -1)
        return -1;
    return 1;
}
