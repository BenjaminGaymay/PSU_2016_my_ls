/*
** t_flag.c for t_flag in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Dec  1 12:15:21 2016 Benjamin GAYMAY
** Last update Thu Dec  1 13:53:50 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <time.h>
#include "my_ls.h"

void		sort_time(t_list **list)
{
  t_list	*tmp;
  int		f;
  long int	time;
  long int	time2;

  f = my_len_list(*list) * my_len_list(*list);
  tmp = *list;
  while ((f = f - 1) >= 0)
    {
      while (tmp->next->next != NULL)
	{
	  time = tmp->next->time;
	  time2 = tmp->next->next->time;
	  check_first(list);
	  if (time < time2)
	    my_swap(tmp, tmp->next);
	  tmp = tmp->next;
	}
      tmp = *list;
    }
}

void		check_time_first(t_list **list)
{
  t_list	*tmp;
  long int	time;
  long int	time2;

  tmp = *list;
  time = tmp->time;
  time2 = tmp->next->time;
  if (time < time2)
    my_swapfirst(list, tmp, tmp->next);
}
