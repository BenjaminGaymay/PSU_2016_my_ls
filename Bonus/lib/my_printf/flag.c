/*
** flag.c for flag in /home/benjamin.g/delivery/PSU_2016_my_printf
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Thu Nov 17 09:37:42 2016 Benjamin GAYMAY
** Last update Fri Nov 25 10:13:39 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my.h"

int		my_plus(va_list ap, char *s, int i)
{
  va_list	aq;

  va_copy(aq, ap);
  if (s[i + 1] == 'i' || s[i + 1] == 'd')
    {
      if (va_arg(aq, int) >= 0)
	my_putchar('+');
    }
  else if (s[i + 1] == 'p')
    {
      if (va_arg(aq, long int) >= 0)
	my_putchar('+');
    }
  else
    my_putstr("%+");
  va_end(aq);
  return (i);
}

int		my_space(va_list ap, char *s, int i)
{
  va_list	aq;
  int		f;

  f = i;
  va_copy(aq, ap);
  while (s[f] == ' ' && s[f] != '\0')
    f++;
  if (s[f] == 'i' || s[f] == 'd')
    {
      if (va_arg(aq, int) >= 0)
	my_putchar(' ');
    }
  else if (s[f] == 'p')
    {
      if (va_arg(aq, int) >= 0)
	my_putchar(' ');
    }
  f--;
  va_end(aq);
  return (f);
}

int		my_hash(va_list ap, char *s, int i)
{
  if (s[i + 1] == 'x')
    my_putstr("0x");
  else if (s[i + 1] == 'X')
    my_putstr("0X");
  else if (s[i + 1] == 'o')
    my_putchar('0');
  else if (s[i + 1] == 'b')
    my_putchar('b');
  return (i);
}
