/*
** my_putchar.c for my_putchar in /home/benjamin.g/save_lib
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct 13 08:26:21 2016 Benjamin GAYMAY
** Last update Fri Nov 25 10:13:30 2016 Benjamin GAYMAY
*/

#include <unistd.h>
#include "my.h"

int	my_putchar_arg(va_list ap)
{
  my_putchar(va_arg(ap, int));
  return (0);
}

int	my_aff_modulo_arg(va_list ap)
{
  my_putchar('%');
  return (0);
}

int	my_aff_atsign_arg(va_list ap)
{
  my_putstr("%@");
  return (0);
}
