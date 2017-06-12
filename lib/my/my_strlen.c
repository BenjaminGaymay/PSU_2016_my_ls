/*
** my_strlen.c for my_strlen in /home/benjamin.g/delivery/CPool_Day04
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct  6 16:36:00 2016 Benjamin GAYMAY
** Last update Sun Nov 20 13:50:33 2016 Benjamin GAYMAY
*/

#include "my.h"

int	my_strlen(char *str1)
{
  int	i;

  i = 0;
  while (str1[i] != '\0')
    {
      i++;
    }
  return (i);
}
