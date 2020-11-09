/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>

int my_printf(char *str, ...);
int my_vprintf(char *str, va_list arg_list);

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);

#endif /* !MY_H_ */