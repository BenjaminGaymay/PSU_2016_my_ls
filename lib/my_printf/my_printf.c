/*
** my_printf.c for my_printf in /home/benjamin.g/delivery/PSU_2021_my_printf
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Mon Nov  7 16:30:28 2016 Benjamin GAYMAY
** Last update Fri Nov 25 10:14:34 2016 Benjamin GAYMAY
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "my.h"

int	(*ptr_funct_type[13])(va_list ap) =
{
  my_putchar_arg,
  my_putstr_arg,
  my_put_nbr_arg,
  my_put_nbr_arg,
  my_put_unsigned_int_arg,
  my_hexa_arg_lower,
  my_hexa_arg_upper,
  my_oct_arg,
  my_hexa_pointer_arg,
  my_putstr_oct_arg,
  my_bin_arg,
  my_aff_modulo_arg,
  my_aff_atsign_arg
};

int	(*ptr_funct_flag[3])(va_list ap, char *s, int i) =
{
  my_hash,
  my_plus,
  my_space
};

int		my_printf(char *s, ...)
{
  va_list	ap;
  char		flag_list[] = "#+ ";
  char		type_list[] = "csdiuxXopSb%";
  int		i;
  int		f;

  i = 0;
  if (s == 0)
    return (0);
  va_start(ap, s);
  while (s[i] != '\0')
    {
      if (s[i] == '%')
	{
	  i = my_flag(flag_list, s, i, ap);
	  i = my_type(type_list, s, i, ap);
	}
      else
	my_putchar(s[i]);
      i++;
    }
  va_end(ap);
  return (0);
}

int	my_flag(char *flag_list, char *s, int i, va_list ap)
{
  int	flag;
  int	f;

  flag = 0;
  f = 0;
  while (flag_list[flag] != s[i + 1] && flag < 4)
    flag++;
  if (flag < 3)
    i = ptr_funct_flag[flag](ap, s, i + 1);
  return (i);
}

int	my_type(char *type_list, char *s, int i, va_list ap)
{
  int	type;

  type = 0;
  while (type_list[type] != s[i + 1] && type < 14)
    type++;
  if (type < 13)
    {
      ptr_funct_type[type](ap);
      i++;
    }
  return (i);
}
