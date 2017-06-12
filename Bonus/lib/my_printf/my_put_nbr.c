/*
** my_put_nbr.c for my_put_nbr in /home/benjamin.g/delivery/CPool_Day03
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Oct  6 09:04:03 2016 Benjamin GAYMAY
** Last update Fri Nov 25 10:14:53 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my.h"

int	my_put_nbr_arg(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
  return (0);
}

int	my_put_nbr_base(int n, int base, int lower_or_upper)
{
  if (n < 0)
    {
      my_put_nbr_base_unsigned(n, base, lower_or_upper);
      return (0);
    }
  if ((n >= 0) && (n < base))
    {
      if (base > 10)
	{
	  if (n > 9)
	    my_putchar(n + lower_or_upper);
	  else
	    my_putchar(n + '0');
	}
      else
	my_putchar(n + '0');
    }
  if (n > base - 1)
    {
      my_put_nbr_base(n / base, base, lower_or_upper);
      my_put_nbr_base(n % base, base, lower_or_upper);
    }
  return (0);
}
