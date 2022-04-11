/*
** EPITECH PROJECT, 2022
** check_error.c
** File description:
** check_error
*/

#include <sys/wait.h>
#include <signal.h>
#include "proto.h"
#include "my_printf.h"

void print_coredump(int status)
{
    if (__WCOREDUMP(status))
        print_error(" (core dumped)\n");
    else if (!(__WCOREDUMP(status)))
        print_error("\n");
}

int check_error(int status)
{
    if (WIFSIGNALED(status)) {
        if (status == 136)
            print_error("Floating exception");
        if (WTERMSIG(status))
            print_error("Segmentation fault");
        print_coredump(status);
        return status;
    }
    return WEXITSTATUS(status);
}
