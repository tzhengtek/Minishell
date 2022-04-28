/*
** EPITECH PROJECT, 2022
** execution_utils.c
** File description:
** execution_utils
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

static void execute_path_arg(char **path, char **arg, char **new_env)
{
    char *exec = NULL;

    for (int i = 0; path[i] != NULL; i++) {
        exec = my_strcat(path[i], arg[0]);
        if (access(exec, X_OK) == 0)
            execve(exec, arg, new_env);
        free(exec);
    }
}

void execute_cmd_path(char **arg, char **new_env, char **path)
{
    if (arg[0] != NULL)
        execve(arg[0], arg, new_env);
    if (path != NULL)
        execute_path_arg(path, arg, new_env);
    my_printf("%e: Command not found.\n", arg[0]);
    exit(0);
}
