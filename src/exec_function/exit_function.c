/*
** EPITECH PROJECT, 2022
** check_exit.c
** File description:
** check_exit
*/

#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

static int check_exit_arg(stock_t *stock, char **arg)
{
    int value = 0;

    if (my_str_isnum(arg[1]) == 1) {
        value = my_getnbr(arg[1]);
        free_all(stock);
        my_printf("exit\n");
        exit(value);
    } else if (((arg[1][0] >= '0' && arg[1][0] <= '9') || arg[1][0] == '-') &&
    (arg[1][1] < '0' || arg[1][1] > '9'))
        print_error("exit: Badly formed number.\n");
    else
        print_error("exit: Expression Syntax.\n");
    return 1;
}

int check_exit(stock_t *stock, char **arg)
{
    if (my_strcmp(arg[0], "exit") == 0) {
        if (my_arrlen(arg) == 1) {
            my_printf("exit\n");
            free_all(stock);
            exit(0);
        }
        if (my_arrlen(arg) > 2) {
            print_error("exit: Expression Syntax.\n");
            return 1;
        }
        if (my_arrlen(arg) > 1)
            return check_exit_arg(stock, arg);
    }
    return 0;
}
