/*
** EPITECH PROJECT, 2021
** my_str_isalpha.c
** File description:
** task 12
*/

int my_str_isalpha(char const *str);

int little_condition(char str, int nb_str)
{
    if (!(str >= 'a' && str <= 'z')) {
        if (!(str >= 'A' && str <= 'Z'))
            nb_str++;
    }
    return nb_str;
}

int my_str_isalpha(char const *str)
{
    int nb_str = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++)
        nb_str = little_condition(str[i], nb_str);
    if (nb_str == 0)
        return 1;
    else
        return 0;
}
