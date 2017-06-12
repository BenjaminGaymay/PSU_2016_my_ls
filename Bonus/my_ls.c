/*
** my_ls.c for my_ls in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Nov 24 13:49:37 2016 Benjamin GAYMAY
** Last update Fri Dec  2 11:19:25 2016 Benjamin GAYMAY
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
  t_stat	buf;

  if (stat(name, &buf) == -1)
    {
      my_printf("ls: cannot access '%s': ", name);
      perror("");
      return (84);
    }
  else
    aff_files(name, flag);
  return (0);
}

void		aff_files(char *name, t_flag **flag)
{
  t_stat	file;
  int		space;
  t_list	*path_list;
  char		a;

  path_list = NULL;
  a = check_a_flag(*flag);
  space = count_space(name, &path_list, flag, a);
  sort_list(&path_list, a);
  check_t_flag(&path_list, *flag);
  check_r_flag(&path_list, *flag);
  while (path_list != NULL)
    {
      stat(path_list->d_file->d_name, &file);
      check_l_flag(path_list->d_file, &file, *flag, space);
      aff_colors(&file, path_list->d_file, flag, space);
      path_list = path_list->next;
    }
  free(path_list);
}

int		count_space(char *name, t_list **path_list, t_flag **flag, char a)
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
      if (d_file->d_name[0] != a)
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

void		aff_colors(t_stat *file, t_dirent *d_file,
			   t_flag **flag, int space)
{
  if (d_file->d_type == DT_DIR)
    my_printf(BLUE "%s\n" WHITE, d_file->d_name);
  else if (d_file->d_type == DT_LNK)
    my_printf(CYAN"%s\n"WHITE, d_file->d_name);
  else if ((file->st_mode) & S_IXUSR == 00100)
    my_printf(GREEN "%s\n" WHITE, d_file->d_name);
  else if (d_file->d_type == DT_LNK)
    my_printf(CYAN"%s\n"WHITE, d_file->d_name);
  else
    my_printf(WHITE "%s\n", d_file->d_name);
}
