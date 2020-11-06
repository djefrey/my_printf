/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print number that is provided
*/

#include "my.h"

static char is_neg(long long nb)
{
    if (nb < 0) {
        my_putchar('-');
        return (1);
    }
    return (0);
}

static unsigned long long get_nbr_length(long long nb)
{
    unsigned long long length = 1;

    while (nb / length > 9) {
        length *= 10;
    }
    return (length);
}

static unsigned long long get_unnbr_length(unsigned long long nb)
{
    unsigned long long length = 1;

    while (nb / length > 9) {
        length *= 10;
    }
    return (length);
}

int my_put_nbr(long long nb)
{
    int digit;
    unsigned long long length;

    if (is_neg(nb))
        nb *= -1;
    length = get_nbr_length(nb);
    while (length > 0) {
        digit = nb / length;
        my_putchar(48 + digit);
        nb = nb - nb / length * length;
        length /= 10;
    }
    return (0);
}

int my_put_unnbr(unsigned long long nb)
{
    int digit;
    unsigned long long length = get_unnbr_length(nb);

    while (length > 0) {
        digit = nb / length;
        my_putchar(48 + digit);
        nb = nb - nb / length * length;
        length /= 10;
    }
    return (0);
}