/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf header
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>

#define NUMBER_FLAGS 6
#define FLAG_PTR_ID 0

typedef void *(*va_list_fct_t) (va_list *arg);
typedef void (*print_fct_t) (void *value);

void *va_list_int(va_list *arg);
void *va_list_char(va_list *arg);
void *va_list_str(va_list *arg);
void *va_list_ptr(va_list *arg);

void print_int(void *value);
void print_char(void *value);
void print_str(void *value);
void print_fullstr(void *value);
void print_ptr(void *value);

const char FLAGS[] = {'p',
                    'd', 'i',
                    'c',
                    's', 'S'};
const va_list_fct_t VA_LIST_FCTS[] = {&va_list_ptr,
                                    &va_list_int, &va_list_int,
                                    &va_list_char,
                                    &va_list_str, &va_list_str};
const print_fct_t PRINT_FCTS[] = {&print_ptr,
                                &print_int, &print_int,
                                &print_char,
                                &print_str, &print_fullstr};

#endif /* !MY_PRINTF_H_ */