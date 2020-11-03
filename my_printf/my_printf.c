/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include "my_printf.h"
#include "my.h"
#include <stdlib.h>

static void check_flag(char *str, va_list *list)
{
    for (int i = 0; i < NUMBER_FLAGS; i++) {
        if (FLAGS[i] == *str) {
            void *value = VA_LIST_FCTS[i](list);
            PRINT_FCTS[i](value);
            free(value);
            return;
        }
    }
}

int my_printf(char *str, ...)
{
    va_list arg_list;

    va_start(arg_list, str);
    while (*str) {
        if (*str == '%') {
            str += 1;
            check_flag(str, &arg_list);
        } else
            my_putchar(*str);
        str += 1;
    }
    va_end(arg_list);
    return (0);
}