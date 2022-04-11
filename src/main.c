/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "proto.h"
#include "my_printf.h"

int main(int ac, char **av, char **env)
{
    if (ac > 1)
        return 84;
    (void)av;
    return minishell(env);
}
