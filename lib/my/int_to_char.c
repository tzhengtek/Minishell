/*
** EPITECH PROJECT, 2021
** int_to_char.c
** File description:
** int_to_char
*/

/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** oya oya oya
*/

#include <stdlib.h>

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb);

int negatif_int(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = -nb;
    }
    return nb;
}

char *int_to_char(int nb)
{
    int power = 0;
    int i = 1;
    int p;
    int j = 0;
    char *str;
    nb = negatif_int(nb);
    if (nb == 0)
        return "0";
    for (i; i <= nb / 10; i *= 10)
        power++;
    str = malloc(sizeof(char) * power + 1);
    for (int start = 0; start != power + 1; start++) {
        p = (nb / i);
        nb = nb - (p * i);
        i /= 10;
        str[j] = p + '0';
        j++;
    }
    str[j] = '\0';
    return str;
}
