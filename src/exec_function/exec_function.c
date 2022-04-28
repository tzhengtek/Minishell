/*
** EPITECH PROJECT, 2022
** execute.c
** File description:
** execute
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "proto.h"
#include "my_printf.h"

static int check_possible_redirection(char **file, char **arg)
{
    int quit = 0;

    if (check_redirection(arg) != -1) {
        quit = redirection_cmd(file, arg);
        if (quit == -1) {
            write(2, *file, my_strlen(*file));
            my_printf("%e\n", ": Permission denied.");
            return 1;
        } else if (quit == 0)
            return 0;
    }
    return -1;
}

static int execute_cmd(char **arg, char **new_env, char **path, char *buff)
{
    int status = 0;
    pid_t pid = fork();
    int quit = 0;
    char *file = NULL;

    if (pid != 0) {
        waitpid(-1, &status, 0);
        return check_error(status);
    } else {
        quit = check_possible_redirection(&file, arg);
        if (quit == 1 || quit == 0)
            exit(quit);
        if (check_pipe_redirection(path, new_env, buff) == 0)
            exit(0);
        execute_cmd_path(arg, new_env, path);
    }
    return 0;
}

static int execute_arg(stock_t *stock, char **arg)
{
    if (my_arrlen(arg) != 0) {
        if (check_setenv(stock, arg) == 1)
            return 1;
        if (check_unsetenv(stock, arg) == 1)
            return 1;
        if (check_exit(stock, arg) == 1)
            return 1;
        if (check_env(arg, stock->new_env) == 1)
            return 1;
        if (check_cd(stock, arg) == 1)
            return 1;
    }
    return 0;
}

int execute(stock_t *stock)
{
    char **arg = NULL;
    int quit = 0;

    for (int i = 0; stock->arg[i] != NULL; i++) {
        arg = str_to_array(stock->arg[i], " \t\n");
        if (execute_arg(stock, arg) == 0 && my_arrlen(arg) != 0)
            quit = execute_cmd
            (arg, stock->new_env, stock->path, stock->arg[i]);
        free_array(arg);
    }
    return quit;
}
