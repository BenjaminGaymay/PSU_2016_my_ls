/*
** my_getnbr.c for my_getnbr in /home/benjamin.g/delivery/CPool_Day04
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Fri Oct  7 14:23:35 2016 Benjamin GAYMAY
** Last update Sun Nov 20 13:43:44 2016 Benjamin GAYMAY
*/

#include "my.h"

int	check_neg(int i, int my_neg, char *str_nbr)
{
  int	a;

  a = 1;
  while (str_nbr[i - a] == '-')
    {
      my_neg = my_neg * (-1);
      a = a + 1;
    }
  return (my_neg);
}

int	my_getnbr(char *str_nbr)
{
  int	i;
  int	my_nbr;
  int	my_neg;

  i = 0;
  my_nbr = 0;
  my_neg = 1;
  while ((str_nbr[i] < '0') || (str_nbr[i] > '9'))
    {
      i++;
    }
  while (('0' <= str_nbr[i]) && (str_nbr[i] <= '9'))
    {
      my_neg = check_neg(i, my_neg, str_nbr);
      my_nbr = my_nbr * 10;
      my_nbr = my_nbr + (str_nbr[i] - 48);
      i++;
    }
  my_nbr = my_nbr * my_neg;
  if ((my_nbr < -2147483637) || (my_nbr > 2147483637))
    {
      return (0);
    }
  return (my_nbr);
}
