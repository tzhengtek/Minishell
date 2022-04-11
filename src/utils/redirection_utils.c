/*
** EPITECH PROJECT, 2022
** redirection_utils.c
** File description:
** redirection_utils
*/

#include <stdlib.h>

int condition_redirection(char *arg)
{
    for (int j = 0; arg[j] != '\0'; j++) {
        if (arg[j] == '>')
            return 1;
    }
    return 0;
}

int check_redirection(char **arg)
{
    for (int i = 0; arg[i] != NULL; i++)
        if (condition_redirection(arg[i]) == 1)
            return i;
    return -1;
}

int check_double_redirection(char **arg, int index, int pos)
{
    if (arg[index][pos] == '>')
        return 1;
    return 0;
}
