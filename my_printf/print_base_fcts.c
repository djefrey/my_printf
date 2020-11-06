/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include "my.h"

void print_octal(void *value)
{
    my_putchar('\\');
    my_putnbr_base_w_zero(*((long long*) (value)), "01234567", 3);
}

void print_binary(void *value)
{
    my_putunnbr_base(*((long long*) (value)), "01");
}

void print_hexa(void *value)
{
    my_putunnbr_base(*((long long*) (value)), "0123456789abcdef");
}

void print_uphexa(void *value)
{
    my_putunnbr_base(*((long long*) (value)), "0123456789ABCDEF");
}