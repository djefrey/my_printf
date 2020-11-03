/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print number that is provided
*/

#include "my.h"

char is_neg(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        return 1;
    }
    return 0;
}

unsigned int get_number_length(long nb)
{
    int length = 1;

    while (nb / length > 9) {
        length *= 10;
    }
    return length;
}

int my_put_nbr(long nb)
{
    int digit;
    unsigned int length;

    if (is_neg(nb))
        nb *= -1;
    length = get_number_length(nb);
    while (length > 0) {
        digit = nb / length;
        my_putchar(48 + digit);
        nb = nb - nb / length * length;
        length /= 10;
    }
    return (0);
}