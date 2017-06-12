/*
** use_list.c for use_list in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Tue Nov 29 15:17:49 2016 Benjamin GAYMAY
** Last update Fri Dec  2 10:45:25 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "include/my_ls.h"

void		my_put_in_list(t_list **list, t_dirent *d_file, time_t time)
{
  t_list	*element;

  element = malloc(sizeof(*element));
  element->d_file = d_file;
  element->time = time;
  element->next = *list;
  *list = element;
}

void		my_put_path_in_list(t_path **list, char *str)
{
  t_path	*element;

  element = malloc(sizeof(*element));
  element->path = str;
  element->next = *list;
  *list = element;
}

void		my_put_flag_in_list(t_flag **list, char flag)
{
  t_flag	*element;

  element = malloc(sizeof(*element));
  element->flag = flag;
  element->next = *list;
  *list = element;
}

int		my_len_list(t_list *list)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = list;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
