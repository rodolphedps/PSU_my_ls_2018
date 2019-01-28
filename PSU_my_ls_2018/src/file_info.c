/*
** EPITECH PROJECT, 2019
** get file info
** File description:
** my_ls
*/

#include "my.h"

void open_ls_dir(DIR *dir, struct dirent *rd)
{
    int i = 0;

    if (!dir) {
        perror("my_ls: cannot open directory");
        exit(84);
    }
    while ((rd = readdir(dir)) != NULL) {
        if (rd->d_name[0] != '.')
            my_printf("%s\n", rd->d_name);
        i++;
    }
}

void print_last_hour(struct stat file)
{
    char *s = ctime(&file.st_mtime);
    int i = 0;

    while (i < 4)
        i++;
    while (i < 16) {
        my_printf("%c", s[i]);
        i++;
    }
}

void print_names(struct stat file)
{
    struct passwd *p;
    struct group *g;

    g = getgrgid(file.st_gid);
    p = getpwuid(file.st_uid);
    my_printf(" %s ", p->pw_name);
    my_printf(" %s ", g->gr_name);
}

void print_rights(struct dirent *rd, struct stat file)
{
    struct tm tim;
    time_t const timezer;

    stat(rd->d_name, &file);
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