/*
** EPITECH PROJECT, 2019
** print w path
** File description:
** my_ls
*/

#include "my.h"

void print_w_path(struct dirent *rd, char *path)
{
    struct tm tim;
    struct stat file;
    time_t const timezer;

    stat(path, &file);
    my_printf((S_ISDIR(file.st_mode)) ? "d" : "-");
    my_printf((file.st_mode & S_IRUSR) ? "r" : "-");
    my_printf((file.st_mode & S_IWUSR) ? "w" : "-");
    my_printf((file.st_mode & S_IXUSR) ? "x" : "-");
    my_printf((file.st_mode & S_IRGRP) ? "r" : "-");
    my_printf((file.st_mode & S_IWGRP) ? "w" : "-");
    my_printf((file.st_mode & S_IXGRP) ? "x" : "-");
    my_printf((file.st_mode & S_IROTH) ? "r" : "-");
    my_printf((file.st_mode & S_IWOTH) ? "w" : "-");
    my_printf((file.st_mode & S_IXOTH) ? "x" : "-");
    print_last_infos(timezer, file);
    my_printf(" %s", rd->d_name);
    my_printf("\n");
}