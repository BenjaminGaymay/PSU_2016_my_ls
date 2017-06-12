/*
** sort_list.c for sort_list in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Tue Nov 29 17:00:41 2016 Benjamin GAYMAY
** Last update Fri Dec  2 11:19:24 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my.h"
#include "my_ls.h"
#include "my_printf.h"

void		sort_list(t_list **list, char a)
{
  t_list	*tmp;
  char		*name;
  char		*name2;
  int		f;

  f = my_len_list(*list) * my_len_list(*list);
  tmp = *list;
  while ((f = f - 1) >= 0)
    {
      while (tmp->next->next != NULL)
	{
	  check_first(list);
	  name = tmp->next->d_file->d_name;
	  name2 = tmp->next->next->d_file->d_name;
	  if (my_strcmp(name, name2) > 0)
	    my_swap(tmp, tmp->next);
	  tmp = tmp->next;
	}
      tmp = *list;
    }
  if (a == '\0')
    my_swapfirst(list, tmp, tmp->next);
}

void		check_first(t_list **list)
{
  char		*name_first;
  char		*name_second;
  t_list	*tmp;

  tmp = *list;
  name_first = tmp->d_file->d_name;
  name_second = tmp->next->d_file->d_name;
  if (my_strcmp(name_first, name_second) > 0)
    my_swapfirst(list, tmp, tmp->next);
}

void		my_swap(t_list *dirent1, t_list *dirent2)
{
  t_list	*dirent3;

  dirent3 = dirent2->next;
  dirent1->next = dirent3;
  dirent2->next = dirent3->next;
  dirent3->next = dirent2;
}

void		my_swapfirst(t_list **list, t_list *dirent1, t_list *dirent2)
{
  dirent1->next = dirent2->next;
  dirent2->next = dirent1;
  *list = dirent2;
}
