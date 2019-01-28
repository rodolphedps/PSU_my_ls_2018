/*
** EPITECH PROJECT, 2019
** file info my ls
** File description:
** my_ls
*/

#include "my.h"

void errors(struct dirent *rd, char **av)
{
    struct stat file;
    int i = 1;

    if (stat(av[i], &file) < 0 && av[i][0] != '-') {
        my_printf("my_ls: cannot acces ");
        perror(av[i]);
        exit(84);
    }
}

int get_total_blocks(DIR *dir, struct dirent *rd, struct stat *file)
{
    int total = 0;

    while ((rd = readdir(dir))) {
        stat(rd->d_name, file);
        if (rd->d_name[0] != '.')
            total += file->st_blocks;
    }
    total = total / 2;
    my_printf("total %d\n", total);
    return (total);
}

void print_last_infos(time_t const timezer, struct stat file)
{
    my_printf(" %d", file.st_nlink);
    print_names(file);
    my_printf("%d ", file.st_size);
    print_last_hour(file);
}

int error_args(int ac, char **av)
{
    int i = 1;

    while (i != ac) {
        if (av[i][0] == '-' && av[i][1] != 'l' && av[i][1] != 'R' &&
        av[i][1] != 'd' && av[i][1] != 'r' && av[i][1] != 't') {
            exit(84);
        }
        i++;
    }
    return (0);
}