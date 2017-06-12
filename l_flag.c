/*
** l_flag.c for l_flag in /home/benjamin.g/delivery/PSU_2016_my_ls
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Tue Nov 29 11:11:52 2016 Benjamin GAYMAY
** Last update Sun Dec  4 20:35:56 2016 Benjamin GAYMAY
*/

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>
#include "my_ls.h"
#include "my_printf.h"
#include "my.h"

char		l_flag(t_dirent *d_file, t_stat *file, int space)
{
  struct passwd	*usr_name;
  struct group	*grp_name;
  char		*date;

  aff_type(d_file);
  rwx_usr(file);
  rwx_grp(file);
  rwx_oth(file);
  usr_name = getpwuid(file->st_uid);
  grp_name = getgrgid(file->st_gid);
  my_printf(" %d %s %s", file->st_nlink, usr_name->pw_name, grp_name->gr_name);
  space = space - my_intlen(file->st_size);
  while (space != 0)
    {
      my_putchar(' ');
      space--;
    }
  my_printf(" %d ", file->st_size);
  write(1, ctime(&file->st_mtime) + 4, 12);
  my_putchar(' ');
  return ('1');
}

void	aff_type(t_dirent *d_file)
{
  if (d_file->d_type == DT_BLK)
    my_putchar('b');
  else if (d_file->d_type == DT_CHR)
    my_putchar('c');
  else if (d_file->d_type == DT_DIR)
    my_putchar('d');
  else if (d_file->d_type == DT_FIFO)
    my_putchar('p');
  else if (d_file->d_type == DT_LNK)
    my_putchar('l');
  else if (d_file->d_type == DT_SOCK)
    my_putchar('s');
  else
    my_putchar('-');
}
