/*
** EPITECH PROJECT, 2018
** functions2.c
** File description:
** func
*/

#include <stdarg.h>
#include "../include/proto.h"

void print_octal(va_list ap)
{
    convert_base(va_arg(ap, int), "01234567");
}

void print_base2(va_list ap)
{
    convert_base(va_arg(ap, int), "01");
}

void print_modulo(va_list ap)
{
    my_putchar('%');
}

void print_adress(va_list ap)
{
    my_putstr("0x");
    convert_base(va_arg(ap, int), "0123456789abcdef");
}

void print_str_to_octal(va_list ap)
{
    print_str_octal(va_arg(ap, char *), "01234567");
}
