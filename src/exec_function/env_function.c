/*
** EPITECH PROJECT, 2022
** env.
** File description:
** env
*/

#include <stdlib.h>
#include "my_printf.h"
#include "proto.h"

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
}

int check_env(char **arg, char **env)
{
    if (strcmp_start(arg[0], "env") == 1) {
        if (no_arg(arg[0], 3) == 1 && arg[1] == NULL) {
            print_env(env);
            return 1;
        }
    }
    return 0;
}
