/*
** hexa_oct.c for hexa_oct in /home/benjamin.g/delivery/PSU_2016_my_printf
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Wed Nov  9 09:12:20 2016 Benjamin GAYMAY
** Last update Fri Nov 25 10:13:52 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my.h"

void	my_hexa(int num, int lower_or_upper)
{
  my_put_nbr_base(num, 16, lower_or_upper);
}

int	my_hexa_arg_upper(va_list ap)
{
  my_hexa(va_arg(ap, int), 55);
  return (0);
}

int	my_hexa_arg_lower(va_list ap)
{
  my_hexa(va_arg(ap, int), 87);
  return (0);
}

void	my_hexa_pointer(long int num)
{
  char	*hex_result;
  int	tmp;
  int	i;

  hex_result = malloc(sizeof(char) * (my_intlen(num) + 1));
  if (hex_result == NULL)
    exit (84);
  i = 0;
  if (num == 0)
    my_putstr("(nil)");
  else
    my_putstr("0x");
  while (num > 0)
    {
      tmp = num % 16;
      if (tmp > 9)
	tmp += 87;
      else
	tmp += '0';
      hex_result[i] = tmp;
      num /= 16;
      i++;
    }
  my_putstr(my_revstr(hex_result));
  free(hex_result);
}

int	my_hexa_pointer_arg(va_list ap)
{
  my_hexa_pointer(va_arg(ap, long int));
  return (0);
}
