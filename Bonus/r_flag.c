/*
** r_flag.c for r_flag in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Wed Nov 30 13:49:38 2016 Benjamin GAYMAY
** Last update Fri Dec  2 10:43:47 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "my_ls.h"

void		rev_list(t_list **list)
{
  t_list	*tmp;
  char		*name;
  char		*name2;
  int		f;

  f = my_len_list(*list) * 2;
  tmp = *list;
  while ((f = f - 1) >= 0)
    {
      while (tmp->next->next != NULL)
	{
	  rev_check_first(list);
	  name = tmp->next->d_file->d_name;
	  name2 = tmp->next->next->d_file->d_name;
	  if (my_strcmp(name, name2) < 0)
	    my_swap(tmp, tmp->next);
	  tmp = tmp->next;
	}
      tmp = *list;
    }
}

void		rev_check_first(t_list **list)
{
  char		*name_first;
  char		*name_second;
  t_list	*tmp;

  tmp = *list;
  name_first = tmp->d_file->d_name;
  name_second = tmp->next->d_file->d_name;
  if (my_strcmp(name_first, name_second) < 0)
    my_swapfirst(list, tmp, tmp->next);
}
