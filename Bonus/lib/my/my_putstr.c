/*
** my_putstr.c for my_putstr in /home/benjamin.g/delivery/CPool_Day04
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct  6 15:28:00 2016 Benjamin GAYMAY
** Last update Wed Nov 30 11:17:23 2016 Benjamin GAYMAY
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
