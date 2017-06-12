/*
** flag.c for flag in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Sat Nov 26 11:21:12 2016 Benjamin GAYMAY
** Last update Thu Dec  1 14:21:54 2016 Benjamin GAYMAY
*/

#include "my_ls.h"

char	r_flag(t_list **list)
{
  rev_list(list);
  return ('1');
}

char	d_flag(t_list **list)
{
  return ('1');
}

char	r2_flag(t_list **list)
{
  return ('1');
}

char	use_t_flag(t_list **list)
{
  sort_time(list);
  return ('1');
}
