/*
** EPITECH PROJECT, 2018
** functions printf
** File description:
** func
*/

#include <stdarg.h>
#include "../include/proto.h"

void print_nbr(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void print_str(va_list ap)
{
    my_putstr(va_arg(ap, const char *));
}

void print_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void print_hexa_min(va_list ap)
{
    convert_base(va_arg(ap, int), "0123456789abcdef");
}

void print_hexa_cap(va_list ap)
{
    convert_base(va_arg(ap, int), "0123456789ABCDEF");
}
