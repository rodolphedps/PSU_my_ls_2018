/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** task02 my_putstr
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int count = 0;
    while (str[count] != '\0') {
        my_putchar(str[count]);
        count++;
    }
    return (0);
}
