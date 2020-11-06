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

#define NUMBER_MODIFIERS 7
#define NUMBER_SPECIFIERS 11
#define FLAG_PTR_ID 0

typedef void *(*va_list_fct_t) (va_list *arg);
typedef void (*print_fct_t) (void *value);

void *va_list_nbchar(va_list *arg);
void *va_list_nbshort(va_list *arg);
void *va_list_nbint(va_list *arg);
void *va_list_nblong(va_list *arg);
void *va_list_nblonglong(va_list *arg);

void *va_list_char(va_list *arg);
void *va_list_str(va_list *arg);
void *va_list_ptr(va_list *arg);

void print_nb(void *value);
void print_unnb(void *value);
void print_octal(void *value);
void print_binary(void *value);
void print_hexa(void *value);
void print_uphexa(void *value);

void print_char(void *value);
void print_str(void *value);
void print_fullstr(void *value);
void print_ptr(void *value);

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