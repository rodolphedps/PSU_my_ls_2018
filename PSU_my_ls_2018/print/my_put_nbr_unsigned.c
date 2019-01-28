/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** put nbr
*/

#include <unistd.h>

void my_putchar(char c);

unsigned int disp_nbr_unsigned(unsigned int nb)
{
    char n;

    if (nb < 0) {
        my_putchar('-');
        n = nb % 10 * -1 + '0';
        disp_nbr_unsigned(nb / 10);
        my_putchar(n);
    }
    if (nb > 0) {
        n = nb % 10 + '0';
        disp_nbr_unsigned(nb / 10);
        my_putchar(n);
    }
    return (0);
}

unsigned int my_put_nbr_unsigned(unsigned int nb)
{
    char n;

    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    disp_nbr_unsigned(nb);
    return (0);
}
