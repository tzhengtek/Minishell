/*
** EPITECH PROJECT, 2022
** cd.c
** File description:
** cd
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my_printf.h"
#include "proto.h"

static int type_arg(char *name)
{
    struct stat info;

    if (stat(name, &info) == -1)
        return 0;
    if (!S_ISDIR(info.st_mode) && !S_ISREG(info.st_mode))
        return 0;
    if (S_ISREG(info.st_mode))
        return -1;
    if (S_ISDIR(info.st_mode))
        return 1;
    return 0;
}

static void cd_dir(char *name, stock_t *stock)
{
    char *save;
    char *pwd = NULL;
    size_t size = 0;

    if (type_arg(name) == -1) {
        print_error(name);
        print_error(": Not a directory.\n");
    }
    if (type_arg(name) == 0) {
        print_error(name);
        print_error(": No such file or directory.\n");
    }
    if (type_arg(name) == 1) {
        save = getcwd(pwd, size);
        chdir(name);
        change_pwd(stock->new_env, stock->home);
        change_oldpwd(stock, save);
        stock->id_cd = 1;
        free(save);
    }
}

static void cd_home(stock_t *stock)
{
    char *pwd = NULL;
    char *save = NULL;
    size_t size = 0;

    save = getcwd(pwd, size);
    change_oldpwd(stock, save);
    chdir(stock->home);
    change_pwd(stock->new_env, stock->home);
    stock->id_cd = 1;
    free(save);
}

static void cd_back(stock_t *stock)
{
    char *save = NULL;
    char *pwd = NULL;
    size_t size = 0;

    if (check_oldpwd(stock->new_env) == 1 && stock->id_cd != 0) {
        save = getcwd(pwd, size);
        chdir(stock->new_env[index_key(stock->new_env, "OLDPWD=")] + 7);
        change_pwd(stock->new_env,
        stock->new_env[index_key(stock->new_env, "OLDPWD=")] + 7);
        change_oldpwd(stock, save);
        stock->id_cd = 1;
        free(save);
    } else
        print_error(": No such file or directory.\n");
}

int check_cd(stock_t *stock, char **arg)
{
    if (my_strcmp(arg[0], "cd") == 0 && my_arrlen(arg) > 2) {
        print_error("cd: Too many arguments.\n");
        return 1;
    }
    if (my_strcmp(arg[0], "cd") == 0) {
        if (arg[1] == NULL)
            cd_home(stock);
        if (arg[1] != NULL && my_strcmp(arg[1], "-") == 0)
            cd_back(stock);
        if (arg[1] != NULL && my_strcmp(arg[1], "-") != 0)
            cd_dir(arg[1], stock);
        return 1;
    }
    return 0;
}
