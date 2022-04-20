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

static void execute_path_arg(char **path, char **arg, char **new_env)
{
    char *exec = NULL;

    for (int i = 0; path[i] != NULL; i++) {
        execve((exec = my_strcat(path[i], arg[0])), arg, new_env);
        free(exec);
    }
}

static int check_possible_redirection(char **file, char **arg)
{
    int quit = 0;

    if (check_redirection(arg) != -1) {
        quit = redirection_cmd(file, arg);
        if (quit == -1) {
            write(2, *file, my_strlen(*file));
            my_printf("%e\n", ": Permission denied.");
            return 1;
        } else if (quit == 0) {
            return 0;
        }
    }
    return -1;
}

static int execute_cmd(char **arg, char **new_env, char **path)
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
        execve(arg[0], arg, new_env);
        if (path != NULL)
            execute_path_arg(path, arg, new_env);
        my_printf("%e: Command not found.\n", arg[0]);
        exit(0);
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

int execute(stock_t *stock, char **arg)
{
    if (execute_arg(stock, arg) == 0 && my_arrlen(arg) != 0)
        return execute_cmd(arg, stock->new_env, stock->path);
    return 0;
}
