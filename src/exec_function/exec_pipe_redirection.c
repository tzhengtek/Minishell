/*
** EPITECH PROJECT, 2022
** exec_pipe_redirection.c
** File description:
** execpipe_redirection
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my_printf.h"
#include "proto.h"

static int nb_pipe(char *buff)
{
    int count = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '|')
            count++;
    }
    return count;
}

static int execute_pipe_redirection
(char *buff, char **path, char **new_env, int *fd)
{
    char **pipe_arg = str_to_array(buff, "|");
    char **arg1 = str_to_array(pipe_arg[0], " \n\t");
    char **arg2 = str_to_array(pipe_arg[1], " \n\t");
    pid_t pid = fork();

    if (pid == 0) {
        dup2(fd[1], 1);
        close(fd[0]);
        execute_cmd_path(arg1, new_env, path);
    } else {
        dup2(fd[0], 0);
        close(fd[1]);
        execute_cmd_path(arg2, new_env, path);
        exit(0);
    }
    free_array(pipe_arg);
    free_array(arg1);
    free_array(arg2);
    return 0;
}

int check_pipe_redirection(char **path, char **new_env, char *buff)
{
    int fd[2];

    if (nb_pipe(buff) == 1) {
        pipe(fd);
        return execute_pipe_redirection(buff, path, new_env, fd);
    }
    return -1;
}
