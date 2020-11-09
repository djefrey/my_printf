/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** nbr struct header
*/

#ifndef NBR_H_
#define NBR_H_

#include <stddef.h>

typedef struct nbr {
    unsigned long long unsign;
    long long sign;
    size_t size;
} nbr_t;

#endif /* !NBR_H_ */