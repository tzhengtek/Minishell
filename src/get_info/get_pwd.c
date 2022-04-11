/*
** EPITECH PROJECT, 2022
** pwd.c
** File description:
** pwd
*/

#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

void change_pwd(char **new_env, char *pwd)
{
    for (int i = 0; new_env[i] != NULL; i++) {
        if (strcmp_start(new_env[i], "PWD=") == 1) {
            free(new_env[i]);
            new_env[i] = my_strcat("PWD=", pwd);
        }
    }
}

int check_oldpwd(char **new_env)
{
    for (int i = 0; new_env[i] != NULL; i++) {
        if (strcmp_start(new_env[i], "OLDPWD") == 1)
            return 1;
    }
    return 0;
}

void change_oldpwd(stock_t *stock, char *save)
{
    int index = 0;

    if (check_oldpwd(stock->new_env) == 1) {
        index = index_key(stock->new_env, "OLDPWD=");
        free(stock->new_env[index]);
        stock->new_env[index] = my_strcat("OLDPWD=", save);
    } else
        add_key_array(stock, "OLDPWD=", save);
}
