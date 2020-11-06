/*
** EPITECH PROJECT, 2020
** my_putnbr_base
** File description:
** convert and display an integer into a number in a given base
*/

#include "my.h"
#include <stdlib.h>

static unsigned long long get_nbr_len(long long nb, int base_size)
{
    long long quotient = nb;
    unsigned long long length = 0;

    while (quotient > 0) {
        quotient = nb / base_size;
        nb = quotient;
        length++;
    }
    return (length);
}
static unsigned long long get_unnbr_len(unsigned long long nb, int base_size)
{
    unsigned long long length = 1;

    while (nb > 0) {
        nb = nb / base_size;
        length++;
    }
    return (length);
}

int my_putnbr_base(long long nb, char const *base)
{
    int base_size = my_strlen(base);
    int remainder = 0;
    unsigned long long length = get_nbr_len(nb, base_size);
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
    for (int i = length - 1; i >= 0; i--)
        my_putchar(str[i]);
    free(str);
    return (0);
}

int my_putunnbr_base(unsigned long long nb, char const *base)
{
    int base_size = my_strlen(base);
    int remainder = 0;
    unsigned long long length = get_nbr_len(nb, base_size);
    char *str = malloc(sizeof(char) * length);

    for (int i = 0; nb > 0; i++) {
        remainder = nb % base_size;
        str[i] = base[remainder];
        nb = nb / base_size;
    }
    for (int i = length - 1; i >= 0; i--)
        my_putchar(str[i]);
    free(str);
    return (0);
}

int my_putnbr_base_w_zero(unsigned long long nb, char const *base, int n_zero)
{
    int base_size = my_strlen(base);
    int remainder = 0;
    unsigned long long length = get_unnbr_len(nb, base_size);
    char *str = malloc(sizeof(char) * length);

    for (int i = 0; nb > 0; i++) {
        remainder = nb % base_size;
        str[i] = base[remainder];
        nb = nb / base_size;
    }
    for (int i = 0; i < (int) ((n_zero + 1) - length); i++)
        my_putchar(base[0]);
    for (int i = length - 2; i >= 0; i--)
        my_putchar(str[i]);
    free(str);
    return (0);
}