/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

int my_printf(char *str, ...);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_fullstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);

int my_put_nbr(long long nb);
int my_put_unnbr(unsigned long long nb);
int my_putnbr_base(long long nb, char const *base);
int my_putunnbr_base(unsigned long long nb, char const *base);
int my_putnbr_base_w_zero(unsigned long long nb, char const *base, int n_zero);

#endif /* !MY_H_ */