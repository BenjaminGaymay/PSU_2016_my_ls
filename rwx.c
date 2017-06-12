/*
** rwx.c for rwx in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Sat Nov 26 11:22:41 2016 Benjamin GAYMAY
** Last update Wed Nov 30 15:27:20 2016 Benjamin GAYMAY
*/

#include "my.h"
#include "my_ls.h"

void	rwx_usr(t_stat *file)
{
  if ((file->st_mode & S_IRUSR) == 0400)
    my_putchar('r');
  else
    my_putchar('-');
  if ((file->st_mode & S_IWUSR) == 0200)
    my_putchar('w');
  else
    my_putchar('-');
  if ((file->st_mode & S_IXUSR) == 0100)
    my_putchar('x');
  else
    my_putchar('-');
}

void	rwx_grp(t_stat *file)
{
  if ((file->st_mode & S_IRGRP) == 0040)
    my_putchar('r');
  else
    my_putchar('-');
  if ((file->st_mode & S_IWGRP) == 0020)
    my_putchar('w');
  else
    my_putchar('-');
  if ((file->st_mode & S_IXGRP) == 0010)
    my_putchar('x');
  else
    my_putchar('-');
}

void	rwx_oth(t_stat *file)
{
  if ((file->st_mode & S_IROTH) == 0004)
    my_putchar('r');
  else
    my_putchar('-');
  if ((file->st_mode & S_IWOTH) == 0002)
    my_putchar('w');
  else
    my_putchar('-');
  if ((file->st_mode & S_IXOTH) == 0001)
    my_putchar('x');
  else
    my_putchar('-');
}
