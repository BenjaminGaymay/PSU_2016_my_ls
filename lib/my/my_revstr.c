/*
** my_revstr.c for my_revstr in /home/benjamin.g/delivery/CPool_Day06
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Mon Oct 10 12:11:06 2016 Benjamin GAYMAY
** Last update Sun Nov 20 13:47:24 2016 Benjamin GAYMAY
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	i;
  int	f;
  int	tmp;

  i = my_strlen(str) - 1;
  f = 0;
  tmp = 0;
  while (i > f)
    {
      tmp = str[f];
      str[f] = str[i];
      str[i] = tmp;
      i = i - 1;
      f = f + 1;
    }
  return (str);
}
