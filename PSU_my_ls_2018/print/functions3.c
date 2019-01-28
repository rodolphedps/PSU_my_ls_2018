/*
** EPITECH PROJECT, 2018
** func3
** File description:
** func
*/

#include <stdarg.h>
#include "../include/proto.h"

void print_unsigned(va_list ap)
{
    print_unsigned_int(va_arg(ap, int));
}
