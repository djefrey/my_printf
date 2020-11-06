/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** va_list_fct
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void *va_list_nbchar(va_list *arg)
{
    char value = (char) (va_arg(*arg, int));
    long long *ptr = malloc(sizeof(long long));

    *ptr = value;
    return (ptr);
}

void *va_list_nbshort(va_list *arg)
{
    short value = (short) (va_arg(*arg, int));
    long long *ptr = malloc(sizeof(long long));

    *ptr = value;
    return (ptr);
}

void *va_list_nbint(va_list *arg)
{
    int value = va_arg(*arg, int);
    long long *ptr = malloc(sizeof(long long));

    *ptr = value;
    return (ptr);
}

void *va_list_nblong(va_list *arg)
{
    long value = va_arg(*arg, long);
    long long *ptr = malloc(sizeof(long long));

    *ptr = value;
    return (ptr);
}

void *va_list_nblonglong(va_list *arg)
{
    long long value = va_arg(*arg, long long);
    long long *ptr = malloc(sizeof(long long));

    *ptr = value;
    return (ptr);
}