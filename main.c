/*
** main.c for main in /home/benjamin.g/delivery/PSU_2016_my_ls_bootstrap
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Nov 24 13:47:48 2016 Benjamin GAYMAY
** Last update Fri Dec  2 10:45:05 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"
#include "my_ls.h"
#include "my_printf.h"

int		main(int ac, char **av)
{
  t_path	*path;
  t_flag	*flag;
  int		i;
  int		f;

  i = 1;
  flag = NULL;
  path = NULL;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  f = 1;
	  while (av[i][f] != '\0')
	    {
	      my_put_flag_in_list(&flag, av[i][f]);
	      f++;
	    }
	}
      else
	my_put_path_in_list(&path, av[i]);
      i++;
    }
  check_validity(&path, &flag);
  return (0);
}

int		check_validity(t_path **path, t_flag **flag)
{
  t_path	*tmp;

  tmp = *path;
  if (check_flag_validity(flag) == 84)
    return (84);
  if (*path == NULL)
    my_ls("./", flag);
  else if ((*path)->next == NULL)
    my_ls(tmp->path, flag);
  else
    {
      while (tmp != NULL)
	{
	  my_ls_path(tmp, flag);
	  tmp = tmp->next;
	}
    }
  return (0);
}

int	my_ls_path(t_path *tmp, t_flag **flag)
{
  my_printf("%s:\n", tmp->path);
  my_ls(tmp->path, flag);
  if (tmp->next != NULL)
    my_putchar('\n');
}

int	check_flag_validity(t_flag **flag)
{
  t_flag	*tmp;

  tmp = *flag;
  while (tmp != NULL)
    {
      if (valid_flag(tmp->flag) == 1)
	tmp = tmp->next;
      else
	{
	  my_printf("ls: invalid option -- '%c'\n", tmp->flag);
	  free(tmp);
	  return (84);
	}
    }
  return (0);
}

int	valid_flag(char flag)
{
  char	flag_list[] = "lRrdt";
  int	i;

  i = 0;
  while (flag_list[i] != '\0')
    {
      if (flag_list[i] == flag)
	return (1);
      i++;
    }
  return (0);
}
