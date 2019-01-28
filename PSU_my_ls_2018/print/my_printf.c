/*
** EPITECH PROJECT, 2018
** my_printf test
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/proto.h"

int convert_base(int nb, char *base)
{
    int len = my_strlen(base);
    int i = 0;

    i = nb % len;
    nb = nb / len;
    if (nb > 0)
        convert_base(nb, base);
    my_putchar(base[i]);
    return (0);
}

int print_str_octal(char *str, char *base)
{
    int i = 0;
    char *s;

    while (str[i] != '\0') {
        if (str[i] > 31 && str[i] < 127)
            my_putchar(str[i]);
        else {
            s = (str[i] <= 7) ? "\\00" : "\\0";
            my_putstr(s);
            convert_base(str[i], base);
        }
        i++;
    }
    return (0);
}

int print_unsigned_int(int nb)
{
    unsigned int a = 0;
    unsigned int n = 4294967295;

    if (nb < 0) {
        nb = nb * -1;
        a = n - nb;
        a = a + 1;
        my_put_nbr_unsigned(a);
    }
    else if (nb >= 0)
        my_put_nbr(nb);
    return (0);
}

int before_printing(char *s, int y, va_list ap)
{
    int x = 0;
    int i = 0;

    if (s[y] == '\0')
        return (i);
    while (x < 13) {
        if (s[y] == to_conversion_functions[x].n) {
            (to_conversion_functions[x]).ptr_function(ap);
            i++;
            return (i);
        }
        x++;
    }
    my_putchar('%');
    return (i);
}

int my_printf(char *s, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, s);
    while (s[i] != '\0') {
        if (s[i] == '%') {
            i++;
            before_printing(s, i, ap);
        } else
            my_putchar(s[i]);
        i++;
    }
    va_end(ap);
    return (0);
}
