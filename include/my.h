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
int my_put_nbr(int nb);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);

char is_printable(char c);

#endif /* !MY_H_ */