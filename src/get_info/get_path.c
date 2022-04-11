/*
** EPITECH PROJECT, 2022
** str_to_array2.c
** File description:
** str_to_array
*/

#include <stdlib.h>
#include "my_printf.h"
#include "proto.h"

void create_path_array(char **array, char *str, char c)
{
    int x = 0;
    int y = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] != c && (str[i + 1] != c || str[i + 1] != '\0')) {
            array[x][y] = str[i];
            y++;
        }
        if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0')) {
            array[x][y] = '\0';
            x++;
            y = 0;
        }
    }
    array[x] = NULL;
}

int count_path_str(char *str, char c)
{
    int count = 0;
    int i = 0;
    for (; str[i + 1] != '\0'; i++) {
        if (str[i] != c && str[i + 1] == c)
            count++;
    }
    if (str[i - 1] != c)
        count++;
    return count;
}

char **path_to_array(char *str, char c)
{
    int count = count_path_str(str, c);
    int size = 0;
    int j = 0;
    char **array = malloc(sizeof(char *) * (count + 1));

    if (array == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c && (str[i + 1] != c || str[i + 1] != '\0'))
            size++;
        if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0')) {
            array[j] = malloc(sizeof(char) * (size + 2));
            j++;
            size = 0;
        }
    }
    create_path_array(array, str, c);
    return array;
}

char **get_path_argument(char *env)
{
    char **array = NULL;
    char *temp = my_strdup(env + 5);
    int save = 0;

    array = path_to_array(temp, ':');
    for (int i = 0; array[i] != NULL; i++) {
        save = my_strlen(array[i]);
        array[i][save] = '/';
        array[i][save + 1] = '\0';
    }
    free(temp);
    return array;
}

char **get_path(char **env)
{
    char **array = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        if (strcmp_start(env[i], "PATH=") == 1)
            array = get_path_argument(env[i]);
    }
    return array;
}
