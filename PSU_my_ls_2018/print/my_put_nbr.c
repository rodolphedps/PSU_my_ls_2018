/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** put nbr
*/

#include <unistd.h>

void my_putchar(char c);

int disp_nbr(int nb)
{
    char n;

    if (nb < 0) {
        my_putchar('-');
        n = nb % 10 * -1 + '0';
        disp_nbr(nb / 10);
        my_putchar(n);
    }
    if (nb > 0) {
        n = nb % 10 + '0';
        disp_nbr(nb / 10);
        my_putchar(n);
    }
}

int my_put_nbr(int nb)
{
    char n;

    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    disp_nbr(nb);
}
