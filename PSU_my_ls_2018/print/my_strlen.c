/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** task03 strlen
*/

int my_strlen(char const *str)
{
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return (count);
}
