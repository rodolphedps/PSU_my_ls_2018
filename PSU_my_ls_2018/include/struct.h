/*
** EPITECH PROJECT, 2018
** struct printf
** File description:
** struct
*/

#pragma once

void print_nbr(va_list ap);
void print_str(va_list ap);
void print_char(va_list ap);
void print_hexa_min(va_list ap);
void print_hexa_cap(va_list ap);
void print_octal(va_list ap);
void print_base2(va_list ap);
void print_modulo(va_list ap);
void print_str_to_octal(va_list ap);
void print_adress(va_list ap);
void print_unsigned(va_list ap);

struct conversion {
    int n;
    void (*ptr_function)(va_list);
};

const struct conversion to_conversion_functions[] = {
    {'d', &print_nbr},
    {'i', &print_nbr},
    {'s', &print_str},
    {'c', &print_char},
    {'b', &print_base2},
    {'%', &print_modulo},
    {'S', &print_str_to_octal},
    {'p', &print_adress},
    {'x', &print_hexa_min},
    {'X', &print_hexa_cap},
    {'o', &print_octal},
    {'u', &print_unsigned},
};
