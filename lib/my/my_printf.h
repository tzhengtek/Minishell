/*
** EPITECH PROJECT, 2021
** my_printf.h
** File description:
** my_printf
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

void my_putstr(char *str);
void my_put_nbr(int nb);
void my_putchar(char c);
int my_getnbr(char *new_str);
int my_compute_power_it(int nb, int p);
void convert_base(unsigned int nb, int base);
char *my_revstr(char *str);
int my_strlen(char *str);
char *my_strdup(char const *src);
char *convert_base_up(unsigned int nb, int base, int token);
long my_put_nbr_long(long nb);
int is_printable(char c);
int is_letter(char c);
void octal_show(char str);
void non_printable(char *str);
int printf_show(char *str, int i, va_list arg);
void my_printf(char *s, ...);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr_unsigned(unsigned int nb);
int print_sign_int(char *str, int i, int nb);
int print_sign_long(char *str, int i, long nb);
int show_hash_hexa(int nb, char *str, int i);
int show_hash_octal(int nb, int i);
int hashtag(char *str, int i, va_list arg);
void show_zero(int nb, char *str);
void special_flag(char *str, int i, int nb_char, va_list arg);
int get_num_str(char *str, int i, va_list arg);
void show_pointer(int nb);
char *int_to_char(int nb);
char *my_strdup(char const *src);
int my_str_isnum(char const *str);
int my_str_isalpha(char const *str);
int little_condition(char str, int nb_str);
void print_error(char *str);
void my_putarr(char **array);
char *my_memset(char *str, char c, int n);
char *my_strcat(char *dest, char *src);
int my_strcmp(char const *s1, char const *s2);
char **str_to_array(char *str, char *separator);

#endif
