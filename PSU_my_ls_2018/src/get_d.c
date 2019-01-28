/*
** EPITECH PROJECT, 2019
** -d my ls
** File description:
** my_ls
*/

#include "my.h"

void d_flag_with_args(DIR *dir, struct dirent *rd, int ac, char **av)
{
    int i = 1;
    char *s;

    while (i != ac) {
        if (av[i][0] != '-') {
            s = av[i];
            my_printf("%s ", s);
        }
        i++;
    }
    my_printf("\n");
}

void open_needed_dir(DIR *dir, struct dirent *rd, char *path)
{
    if (!dir) {
        perror("my_ls: cannot acces");
        exit(84);
    }
    while ((rd = readdir(dir))) {
        if (rd->d_name[0] != '.') {
            print_w_path(rd, path);
        }
    }
}

void l_flag_with_args(DIR *dir, struct dirent *rd, int ac, char **av)
{
    int i = 1;
    struct stat file;
    char *path = av[i];

    while (i != ac) {
        stat(av[i], &file);
        switch (file.st_mode & S_IFMT) {
            case S_IFREG:
                print_rights(rd, file);
                break;
            case S_IFDIR:
                dir = opendir(av[i]);
                open_needed_dir(dir, rd, av[i]);
                break;
        }
        i++;
    }
}

void get_cases_with_args(DIR *dir, struct dirent *rd, char **av, int ac)
{
    int i = 1;

    while (i != ac) {
        if (av[i][0] == '-' && av[i][1] == 'd')
            d_flag_with_args(dir, rd, ac, av);
        if (av[i][0] == '-' && av[i][1] == 'l') {
            l_flag_with_args(dir, rd, ac, av);
        }
        i++;
    }
}

int is_file_or_dir(struct stat file, DIR *dir, struct dirent *rd, char *path)
{
    switch (file.st_mode & S_IFMT) {
        case S_IFREG:
            my_printf("%s\n", path);
            break;
        case S_IFDIR:
            dir = opendir(path);
            open_ls_dir(dir, rd);
            break;
    }
    return (0);
}