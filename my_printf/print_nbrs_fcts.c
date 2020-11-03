/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_fcts
*/

#include "my.h"

void print_short(void *value)
{
    my_put_nbr(*((short*) (value)));
}

void print_int(void *value)
{
    my_put_nbr(*((int*) (value)));
}

void print_long(void *value)
{
    my_put_nbr(*((long*) (value)));
}

void print_binary(void *value)
{
    my_putnbr_base(*((long*) (value)), "01");
}

void print_hexa(void *value)
{
    my_putnbr_base(*((long*) (value)), "0123456789abcdef");
}