/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf header
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include "flags.h"

#define NUMBER_FLAGS 5
#define NUMBER_MODIFIERS 7
#define NUMBER_SPECIFIERS 11
#define FLAG_PTR_ID 0

typedef void *(*va_list_fct_t) (va_list *arg);
typedef int (*print_fct_t) (void *value, int flags, int fwidth);

int my_printf(char *str, ...);
int my_vprintf(char *str, va_list arg_list);

void *va_list_nbchar(va_list *arg);
void *va_list_nbshort(va_list *arg);
void *va_list_nbint(va_list *arg);
void *va_list_nblong(va_list *arg);
void *va_list_nblonglong(va_list *arg);

void *va_list_char(va_list *arg);
void *va_list_str(va_list *arg);
void *va_list_ptr(va_list *arg);

int print_nb(void *value, int flags, int fwidth);
int print_unnb(void *value, int flags, int fwidth);
int print_octal(void *value, int flags, int fwidth);
int print_binary(void *value, int flags, int fwidth);
int print_hexa(void *value, int flags, int fwidth);
int print_uphexa(void *value, int flags, int fwidth);

int print_char(void *value, int flags, int fwidth);
int print_str(void *value, int flags, int fwidth);
int print_fullstr(void *value, int flags, int fwidth);
int print_ptr(void *value, int flags, int fwidth);

const char FLAGS[] = {'#', '0', '-', ' ', '+'};

const char FLAG_VALUES[] = {FLAG_HASHTAG, FLAG_ZERO, FLAG_MINUS,
                            FLAG_BLANK , FLAG_SIGN};

const char *MODIFIERS[] = {"hh", "h", "ll", "l",
                            "j", "z", "t"};

const va_list_fct_t VA_LIST_MOD[] = {&va_list_nbchar, &va_list_nbshort,
                            &va_list_nblonglong, &va_list_nblong,
                            &va_list_nblonglong, &va_list_nbint,
                            &va_list_nbint};

const char SPECIFIERS[] = {'p',
                        'o', 'u',
                        'd', 'i',
                        'c',
                        's', 'S',
                        'b', 'x', 'X'};

const va_list_fct_t VA_LIST_SPEC[] = {&va_list_ptr,
                                NULL, NULL,
                                NULL, NULL,
                                &va_list_char,
                                &va_list_str, &va_list_str,
                                NULL, NULL, NULL};

const print_fct_t PRINT_FCTS[] = {&print_ptr,
                                &print_octal, &print_unnb,
                                &print_nb, &print_nb,
                                &print_char,
                                &print_str, &print_fullstr,
                                &print_binary, &print_hexa, &print_uphexa};

#endif /* !MY_PRINTF_H_ */