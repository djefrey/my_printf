/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** print_field_width
*/

#ifndef PRINT_FIELD_WIDTH_H_
#define PRINT_FIELD_WIDTH_H_

int print_zeros_or_spaces(int fwidth, int len, int flags);
int print_zeros(int fwidth, int len, int flags);
int print_left_spaces(int fwidth, int len, int flags);
int print_right_spaces(int fwidth, int len, int flags);

#endif /* !PRINT_FIELD_WIDTH_H_ */