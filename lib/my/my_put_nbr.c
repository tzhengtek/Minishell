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

int int_is_neg(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = -nb;
    }
    return nb;
}

int my_put_nbr(int nb)
{
    int power = 0;
    int i = 1;
    int p;
    int start = 0;

    nb = int_is_neg(nb);
    if (nb == 0) {
        my_putchar(48);
        return 0;
    }
    for (i; i <= nb / 10; i *= 10)
        power++;
    for (start; start != power + 1; start++) {
        p = (nb / i);
        nb = nb - (p * i);
        i /= 10;
        my_putchar(p + 48);
    }
}
