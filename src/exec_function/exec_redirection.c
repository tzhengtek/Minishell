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
    new_array[size] = NULL;
    free_array(arg);
    return new_array;
}

int redirection_type_function(int state, int fd, struct stat bytes)
{
    char *empty = NULL;
    int nb = bytes.st_size;

    if (state == 1) {
        empty = malloc(sizeof(char) * (nb + 1));
        for (int i = 0; i < nb; i++)
            empty[i] = '\0';
        if (write(fd, empty, nb) == -1)
            return -1;
        free(empty);
    }
    return 0;
}

int redirection_cmd(char **file, int fd, char **arg)
{
    int state = 0;
    struct stat bytes;

    if ((*file = get_redirection_file(arg, &state)) == NULL)
        return 0;
    fd = open(*file, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1)
        return -1;
    if (stat(*file, &bytes) == -1)
        return -1;
    if (redirection_type_function(state, fd, bytes) == -1)
        return -1;
    dup2(fd, 1);
    return 1;
}
