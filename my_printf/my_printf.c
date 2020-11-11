/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my.h"

static void check_flags_and_modifiers(char **str, int *flags,
va_list_fct_t *length_modif, int *length)
{
    for (int i = 0; i < NUMBER_FLAGS; i++) {
        if (**str == FLAGS[i]) {
            if (FLAG_VALUES[i] == FLAG_MINUS && *flags & FLAG_ZERO)
                *flags -= FLAG_ZERO;
            else if (FLAG_VALUES[i] == FLAG_SIGN && *flags & FLAG_BLANK)
                *flags -= FLAG_BLANK;
            *flags += FLAG_VALUES[i];
            *str += 1;
        }
    }
    for (int i = 0; i < NUMBER_MODIFIERS; i++) {
        if (!my_strcmp(*str, MODIFIERS[i])) {
            *length_modif = VA_LIST_MOD[i];
            *str += my_strlen(MODIFIERS[i]);
            *length += my_strlen(MODIFIERS[i]);
            break;
        }
    }
}

static int check_special_flags(char **str)
{
    if (**str == '%') {
        my_putchar('%');
        *str += 1;
        return (1);
    }
    return (0);
}

static int check_flag(char **str, va_list *list, int *length)
{
    void *value = NULL;
    va_list_fct_t length_modif = &va_list_nbint;
    int flags = 0;
    int field_width = 0;

    check_flags_and_modifiers(str, &flags, &length_modif, length);
    while (**str >= '0' && **str <= '9') {
        field_width = field_width * 10 + (**str - 48);
        *str += 1;
    }
    if (check_special_flags(str))
        return (1);
    for (int i = 0; i < NUMBER_SPECIFIERS; i++) {
        if (**str == SPECIFIERS[i]) {
            value = VA_LIST_SPEC[i] != NULL ?
            VA_LIST_SPEC[i](list) : (*length_modif)(list);

            PRINT_FCTS[i](value, flags, field_width);
            if (i != FLAG_PTR_ID)
                free(value);
            *str += 1;
            *length += 1;
            return (1);
        }
    }
    return (0);
}

int my_vprintf(char *str, va_list arg_list)
{
    int length = 0;
    va_list arg_cpy;

    va_copy(arg_cpy, arg_list);
    while (*str) {
        if (*str == '%') {
            str += 1;
            length += 1;
            if (!check_flag(&str, &arg_cpy, &length)) {
                my_putchar('%');
                my_putchar(*str);
                str += 1;
                length += 1;
            }
        } else {
            my_putchar(*str);
            str += 1;
            length += 1;
        }
    }
    return (length);
}

int my_printf(char *str, ...)
{
    va_list arg_list;
    int length;

    va_start(arg_list, str);
    length = my_vprintf(str, arg_list);
    va_end(arg_list);
    return (length);
}