/*
** my_ls.c for my_ls in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Nov 24 13:49:37 2016 Benjamin GAYMAY
** Last update Sun Dec  4 20:54:14 2016 Benjamin GAYMAY
*/

#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include "my_ls.h"
#include "my_printf.h"

int		my_ls(char *name, t_flag **flag)
{
  DIR		*repo;
  t_stat	buf;
  t_dirent	*d_file;

  if (stat(name, &buf) == -1)
    {
      my_printf("ls: cannot access '%s': ", name);
      perror("");
      return (84);
    }
  if ((repo = opendir(name)) == 0)
    my_printf("%s\n", name);
  else
    aff_files(name, flag);
  closedir(repo);
  return (0);
}

void		aff_files(char *name, t_flag **flag)
{
  t_stat	file;
  t_list	*path_list;
  int		space;

  path_list = NULL;
  space = count_space(name, &path_list, flag);
  check_t_flag(&path_list, *flag);
  check_r_flag(&path_list, *flag);
  while (path_list != NULL)
    {
      stat(path_list->d_file->d_name, &file);
      check_l_flag(path_list->d_file, &file, *flag, space);
      my_printf("%s\n", path_list->d_file->d_name);
      path_list = path_list->next;
    }
  free(path_list);
}

int		count_space(char *name, t_list **path_list, t_flag **flag)
{
  DIR		*repo;
  t_dirent	*d_file;
  t_stat	file;
  int		space;
  int		total;

  repo = opendir(name);
  space = 0;
  total = 0;
  while ((d_file = readdir(repo)) != NULL)
    {
      if (d_file->d_name[0] != '.')
	{
	  stat(d_file->d_name, &file);
	  my_put_in_list(path_list, d_file, file.st_mtime);
	  total = total + file.st_blocks;
	  if (my_intlen(file.st_size) > space)
	    space = my_intlen(file.st_size);
	}
    }
  aff_total(total, flag);
  closedir(repo);
  return (space);
}
