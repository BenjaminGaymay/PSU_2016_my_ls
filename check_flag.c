/*
** check_flag.c for check_flag in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Wed Nov 30 15:56:56 2016 Benjamin GAYMAY
** Last update Sun Dec  4 20:32:02 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include "my_ls.h"
#include "my_printf.h"

void		check_l_flag(t_dirent *d_file, t_stat *file,
			     t_flag *flag, int space)
{
  char		valid_flag[2];

  valid_flag[0] = '0';
  valid_flag[1] = '\0';
  while (flag != NULL)
    {
      if (valid_flag[0] == '0' && flag->flag == 'l')
	valid_flag[0] = l_flag(d_file, file, space);
      else
	flag = flag->next;
    }
}

void		check_r_flag(t_list **path, t_flag *flag)
{
  char		valid_flag[2];

  valid_flag[0] = '0';
  valid_flag[1] = '\0';
  while (flag != NULL)
    {
      if (valid_flag[0] == '0' && flag->flag == 'r')
	valid_flag[0] = r_flag(path);
      else
	flag = flag->next;
    }
}

void		check_t_flag(t_list **path, t_flag *flag)
{
  char		valid_flag[2];

  valid_flag[0] = '0';
  valid_flag[1] = '\0';
  while (flag != NULL)
    {
      if (valid_flag[0] == '0' && flag->flag == 't')
	valid_flag[0] = use_t_flag(path);
      else
	flag = flag->next;
    }
}

int		aff_total(int total, t_flag **flag)
{
  t_flag	*tmp;

  tmp = *flag;
  while (tmp != NULL)
    {
      if (tmp->flag == 'l')
	{
	  my_printf("total %d\n", total / 2);
	  return (0);
	}
      tmp = tmp->next;
    }
  free(tmp);
  return (0);
}
