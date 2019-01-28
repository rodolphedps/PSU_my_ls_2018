/*
** EPITECH PROJECT, 2019
** my.h my_ls
** File description:
** my_ls
*/

#pragma once

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>

int my_printf(char *s, ...);
void print_rights(struct dirent *rd, struct stat file);
void print_w_path(struct dirent *rd, char *path);
void print_names(struct stat file);
void print_last_hour(struct stat file);
void print_month(time_t const timezer);
void print_last_mon(time_t const timezer, struct tm *mon);
void print_last_infos(time_t const timezer, struct stat file);
int error_args(int ac, char **av);
int get_total_blocks(DIR *dir, struct dirent *rd, struct stat *file);
void d_flag_with_args(DIR *dir, struct dirent *rd, int ac, char **av);
void get_cases_with_args(DIR *dir, struct dirent *rd, char **av, int ac);
void open_ls_dir(DIR *dir, struct dirent *rd);
void open_ls_dir_and_before(DIR *dir, struct dirent *rd, char **av);
int is_file_or_dir(struct stat file, DIR *dir, struct dirent *rd, char *path);
void errors(struct dirent *rd, char **av);


typedef struct ls_s {
    char *s;
}              ls_t;