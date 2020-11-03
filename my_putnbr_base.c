/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** convert and display an integer into a number in a given base
*/

#include "my.h"
#include <stdlib.h>

static unsigned long get_nbr_len(long nb, int base_size)
{
    long quotient = nb;
    unsigned long length = 0;

    while (quotient > 0) {
        quotient = nb / base_size;
        nb = quotient;
        length++;
    }
    return (length);
}

int my_putnbr_base(long nb, char const *base)
{
    int base_size = my_strlen(base);
    int remainder = 0;
    unsigned long length = get_nbr_len(nb, base_size);
    char *str = malloc(sizeof(char) * length);

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (int i = 0; nb > 0; i++) {
        remainder = nb % base_size;
        str[i] = base[remainder];
        nb = nb / base_size;
    }
    for (int i = length; i >= 0; i--)
        my_putchar(str[i]);
    free(str);
    return (0);
}