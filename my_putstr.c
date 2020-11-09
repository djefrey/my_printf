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