/*
** my_strcmp.c for my_strcmp in /home/benjamin.g/delivery/PSU_2016_my_ls/lib/my
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Dec  1 10:14:23 2016 Benjamin GAYMAY
** Last update Thu Dec  1 12:14:24 2016 Benjamin GAYMAY
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] != '\0') && (s2[i] != '\0'))
    {
      if ((s1[i] >= 'A' && s1[i] <= 'Z')
	  && (s2[i] >= 'a' && s2[i] <= 'z'))
	{
	  if ((s1[i] + 32) != s2[i])
	    return ((s1[i] + 32) - s2[i]);
	}
      else if ((s1[i] >= 'a' && s1[i] <= 'z')
	       && (s2[i] >= 'A' && s2[i] <= 'Z'))
	{
	  if ((s2[i] + 32) != s1[i])
	    return (s1[i] - (s2[i] + 32));
	}
      else if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  return (0);
}
