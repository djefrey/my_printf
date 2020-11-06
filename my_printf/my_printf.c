/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my.h"

static int print_percent(char **str)
{
    my_putchar('%');
    *str += 1;
    return (1);
}

static void print_specifier(int i, char **str, va_list *list,
va_list_fct_t length_modif)
{
    void *value = VA_LIST_SPEC[i] != NULL ?
    VA_LIST_SPEC[i](list) : (*length_modif)(list);

    PRINT_FCTS[i](value);
    if (i != FLAG_PTR_ID)
        free(value);
    *str += 1;
}

static int check_flag(char **str, va_list *list)
{
    va_list_fct_t length_modif = &va_list_nbint;

    for (int i = 0; i < NUMBER_MODIFIERS; i++) {
        if (!my_strcmp(*str, MODIFIERS[i])) {
            length_modif = VA_LIST_MOD[i];
            *str += my_strlen(MODIFIERS[i]);
            break;
        }
    }
    if (**str == '%')
        return (print_percent(str));
    for (int i = 0; i < NUMBER_SPECIFIERS; i++) {
        if (**str == SPECIFIERS[i]) {
            print_specifier(i, str, list, length_modif);
            return (1);
        }
    }
    return (0);
}

int my_printf(char *str, ...)
{
    va_list arg_list;

    va_start(arg_list, str);
    while (*str) {
        if (*str == '%') {
            str += 1;
            if (!check_flag(&str, &arg_list)) {
                my_putchar('%');
                my_putchar(*str);
                str += 1;
            }
        } else {
            my_putchar(*str);
            str += 1;
        }
    }
    va_end(arg_list);
    return (0);
}