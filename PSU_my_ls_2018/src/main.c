/*
** EPITECH PROJECT, 2019
** main my_ls
** File description:
** my_ls
*/

#include "my.h"

void get_basic_ls(DIR *dir, struct dirent *rd)
{
    if (rd->d_name[0] != '.')
        my_printf("%s\n", rd->d_name);
}

void get_l_flag(char **av, int ac, DIR *dir, struct dirent *rd)
{
    struct stat file;

    get_total_blocks(dir, rd, &file);
    closedir(dir);
    if ((dir = opendir(".")) == NULL)
        exit(84);
    while ((rd = readdir(dir))) {
        stat(rd->d_name, &file);
        if (rd->d_name[0] != '.')
            print_rights(rd, file);
    }
    return ;
}

int get_ls_cases(DIR *dir, struct dirent *rd, char **av, int ac)
{
    int i = 1;
    struct stat file;
    char *path = av[i];

    while (i < ac) {
        stat(path, &file);
        is_file_or_dir(file, dir, rd, path);
        if (av[i][0] == '-' && av[i][1] == 'l')
            get_l_flag(av, ac, dir, rd);
        if (av[i][0] == '-' && av[i][1] == 'd')
            my_printf(".\n");
        i++;
    }
    return (0);
}

int find_args(int ac, char **av, ls_t *ls)
{
    DIR *dir;
    struct dirent *rd;

    error_args(ac, av);
    if (ac == 1) {
        if ((dir = opendir(".")) == NULL)
            exit(84);
        while ((rd = readdir(dir)))
            get_basic_ls(dir, rd);
        closedir(dir);
    }
    else if (ac == 2) {
        errors(rd, av);
        if ((dir = opendir(".")) == NULL)
            exit(84);
        get_ls_cases(dir, rd, av, ac);
    }
    else
        get_cases_with_args(dir, rd, av, ac);
}

int main(int ac, char **av)
{
    ls_t *ls = malloc(sizeof(ls_t));
    find_args(ac, av, ls);
    return (0);
}