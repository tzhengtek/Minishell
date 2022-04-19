/*
** EPITECH PROJECT, 2022
** redirection_type_utils.c
** File description:
** redirection_type_utils
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "proto.h"
#include "my_printf.h"

int redirection_stdout(int state, char *file)
{
    int fd = open(file, O_RDWR | O_CREAT | ((state == 1) ? O_TRUNC : O_APPEND),
    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

    if (fd == -1)
        return -1;
    dup2(fd, 1);
    close(fd);
    return 0;
}

int redirection_stdin(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return -1;
    dup2(fd, 0);
    close(fd);
    return 0;
}

int double_redirection_stdin(char *file)
{
    char *buff = NULL;
    size_t size = 0;

    my_printf("? ");
    while (getline(&buff, &size, stdin) != -1) {
        my_memset(buff, '\0', my_strlen(buff) - 1);
        if (my_strcmp(buff, file) == 0)
            break;
        my_printf("? ");
    }
    free(buff);
    free(file);
    return 0;
}
