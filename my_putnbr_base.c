/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** convert and display an integer into a number in a given base
*/

#include "my.h"

int my_putnbr_base(long nb, char const *base)
{
    int base_size = my_strlen(base);
    long quotient = nb;
    int remainder = 0;
    char str[32] = {0};
    int length = 0;

    if (is_neg(nb)) {
        nb *= -1;
        quotient *= -1;
    }
    while (quotient > 0) {
        quotient = nb / base_size;
        remainder = nb - quotient * base_size;
        str[length] = base[remainder];
        nb = quotient;
        length++;
    }
    for (int i = length; i >= 0; i--)
        my_putchar(str[i]);
    return (0);
}
