/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_print_nbr
*/

#ifndef MY_PRINT_NBR_H_
#define MY_PRINT_NBR_H_

int printf_get_nbr(long long nb, int flags);
int printf_get_unbr(unsigned long long nb, int flags);
int printf_get_nbr_base(long long nb, char const *base, int flags);
int printf_get_unbr_base(unsigned long long nb, char const *base, int flags);

#endif /* !MY_PRINT_NBR_H_ */