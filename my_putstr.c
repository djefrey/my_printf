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

    for (int i = 0; str[i]; i++) {
        c = str[i];
        if (c >= 32)
            my_putchar(c);
        else {
            my_putchar('\\');
            my_putnbr_base_w_zero(c, "01234567", 3);
        }
    }
    return (0);
}