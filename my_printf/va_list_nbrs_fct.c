/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** va_list_fct
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void *va_list_short(va_list *arg)
{
    short value = va_arg(*arg, int);
    short *ptr = malloc(sizeof(short));

    *ptr = value;
    return ((void*) (ptr));
}

void *va_list_int(va_list *arg)
{
    int value = va_arg(*arg, int);
    int *ptr = malloc(sizeof(int));

    *ptr = value;
    return ((void*) (ptr));
}

void *va_list_long(va_list *arg)
{
    long value = va_arg(*arg, long);
    long *ptr = malloc(sizeof(long));

    *ptr = value;
    return ((void*) (ptr));
}