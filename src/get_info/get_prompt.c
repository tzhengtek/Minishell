/*
** EPITECH PROJECT, 2022
** prompt.c
** File description:
** prompt
*/

#include <unistd.h>
#include <stdlib.h>
#include "proto.h"
#include "my_printf.h"

char *my_remalloc(char *final, char *src)
{
    char *save = NULL;

    save = my_strdup(final);
    free(final);
    final = my_strcat(save, src);
    free(save);
    return final;
}

int get_pwd_info(char *pwd)
{
    int nb_slash = 0;
    int count = 0;

    for (; pwd[count] != '\0' && nb_slash != 2; count++) {
        if (pwd[count] == '/')
            nb_slash++;
    }
    return count;
}

void free_buffer(char *buff1, char *buff2, char *buff3, char *buff4)
{
    free(buff1);
    free(buff2);
    free(buff3);
    free(buff4);
}

char *get_prompt(void)
{
    char *buff = NULL;
    char *pwd = getcwd(buff, 0);
    char *save = NULL;
    char *final = NULL;
    char *usr = NULL;
    int count = get_pwd_info(pwd);

    usr = my_strdup(pwd + count);
    usr = my_memset(usr, '\0', index_character(usr, '/', 1));
    if (my_strlen(usr) != 0 && usr[my_strlen(usr) - 1] == '/')
        usr = my_memset(usr, '\0', my_strlen(usr) - 1);
    final = my_strcat("[", usr);
    save = my_strdup(pwd + return_index(pwd, '/'));
    final = my_remalloc(final, "@fedora ");
    final = my_remalloc(final, save);
    final = my_remalloc(final, "]");
    free_buffer(usr, pwd, save, buff);
    return final;
}
