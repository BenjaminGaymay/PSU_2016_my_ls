/*
** my_strlen.c for my_strlen in /home/benjamin.g/delivery/CPool_Day04
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct  6 16:36:00 2016 Benjamin GAYMAY
** Last update Fri Nov 25 10:15:50 2016 Benjamin GAYMAY
*/

#include "my.h"

int	my_intlen(int nb)
{
  int	i;

  i = 0;
  while (nb != 0)
    {
      nb /= 10;
      i++;
    }
  return (i);
}
