/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** oya oya oya
*/

#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);

long long_is_neg(long nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = -nb;
    }
    return nb;
}

long my_put_nbr_long(long nb)
{
    long power = 0;
    long i = 1;
    long p;
    long start = 0;

    nb = long_is_neg(nb);
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
