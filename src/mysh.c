/*
** EPITECH PROJECT, 2022
** mysh.c
** File description:
** mysh
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

int execute_command(stock_t *stock, char *buff, int quit)
{
    stock->arg = check_multiple_arg(buff);
    stock->id_arg = 1;
    for (int i = 0; stock->arg[i] != NULL; i++)
        quit = execute(stock, stock->arg[i]);
    free(stock->prompt);
    stock->prompt = get_prompt();
    if (stock->path != NULL)
        free_array(stock->path);
    stock->path = get_path(stock->new_env);
    my_printf("%s$ ", stock->prompt);
    free_all_arg(stock->arg);
    if (stock->id_arg == 1)
        stock->id_arg = 0;
    return quit;
}

int minishell(char **env)
{
    size_t size = 0;
    char *buff = NULL;
    int nb = 0;
    int quit = 0;
    stock_t *stock = create_stock(env);

    my_printf("%s$ ", stock->prompt);
    while ((nb = getline(&buff, &size, stdin)) != -1) {
        if (nb > 1)
            quit = execute_command(stock, buff, quit);
        else
            my_printf("%s$ ", stock->prompt);
    }
    free_everything(stock, buff);
    my_printf("exit\n");
    return quit;
}
