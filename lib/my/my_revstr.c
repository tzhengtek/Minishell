/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** TAsk03
*/

void my_putchar(char c);

char *my_revstr(char *str);

int my_strlen(char *c);

char *my_revstr(char *str)
{
    int i = 0;
    int b = 0;
    int value;
    char inter;

    b = my_strlen(str);
    value = b - 1;
    while (i < b / 2) {
        inter = str[i];
        str[i] = str[value];
        str[value] = inter;
        i++;
        value--;
    }
    return (str);
}
