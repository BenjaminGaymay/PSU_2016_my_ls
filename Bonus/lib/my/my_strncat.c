/*
** my_strncat.c for my_strncat in /home/benjamin.g/delivery/CPool_Day07/lib/my
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Tue Oct 11 13:36:58 2016 Benjamin GAYMAY
** Last update Mon Nov 28 13:15:26 2016 Benjamin GAYMAY
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	f;

  i = 0;
  f = nb;
  while (dest[i] != '\0')
    i++;
  while (src[f] != '\0')
    {
      dest[i] = src[f];
      i++;
      f++;
    }
  dest[i] = ' ';
  dest[i + 1] = '\0';
  return (dest);
}
