/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** print each character of a string
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    write(1, str, len);
    return (0);
}

int my_put_fullstr(char const *str)
{
    char c;
    char *nbr_str;
    int len;

    for (int i = 0; str[i]; i++) {
        c = str[i];
        if (c >= 32)
            my_putchar(c);
        else {
            my_putchar('\\');
            nbr_str = printf_get_unbr_base(c, "01234567", 0);
            len = my_strlen(nbr_str);
            for (int i = 3; i - len > 0; i--)
                my_putchar('0');
            my_putstr(nbr_str);
        }
    }
    return (0);
}