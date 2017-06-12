/*
** my_ls.h for my_ls in /home/benjamin.g/delivery/PSU_2016_my_ls/include
** 
** Made by Benjamin GAYMAY
** Login   <benjamin.g@epitech.net>
** 
** Started on  Fri Nov 25 10:28:41 2016 Benjamin GAYMAY
** Last update Fri Dec  2 11:21:02 2016 Benjamin GAYMAY
*/

#ifndef MY_LS_H
# define MY_LS_H

#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

# define BLUE "\033[1;34m"
# define WHITE "\033[0m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"

typedef struct dirent	t_dirent;
typedef struct stat	t_stat;

typedef struct	s_list
{
  t_dirent	*d_file;

  time_t	time;

  struct s_list	*next;
}		t_list;

typedef struct	s_path
{
  char		*path;

  struct s_path	*next;
}		t_path;

typedef struct	s_flag
{
  char		flag;

  struct s_flag	*next;
}		t_flag;

int	check_validity(t_path **path, t_flag **flag);
int	my_ls_path(t_path *tmp, t_flag **flag);
int	check_flag_validity(t_flag **flag);
int	valid_flag(char flag);

void	my_put_in_list(t_list **list, t_dirent *d_file, time_t time);
void	my_put_path_in_list(t_path **list, char *str);
void	my_put_flag_in_list(t_flag **list, char flag);
int	my_len_list(t_list *list);

int	my_ls(char *name, t_flag **flag);
int	count_space(char *name, t_list **path_list, t_flag **flag, char a);
void	aff_files(char *name, t_flag **flag);
void	aff_colors(t_stat *file, t_dirent *d_file, t_flag **flag, int space);

void	check_l_flag(t_dirent *d_file, t_stat *file, t_flag *flag, int space);
void	check_r_flag(t_list **path, t_flag *flag);
void	check_t_flag(t_list **path, t_flag *flag);
char	check_a_flag(t_flag *flag);
int	aff_total(int total, t_flag **flag);

char	l_flag(t_dirent *d_file, t_stat *file, int space);
void	aff_type(t_dirent *d_file);

char	r_flag(t_list **list);
char	d_flag(t_list **list);
char	r2_flag(t_list **list);
char	use_t_flag(t_list **list);

void	rwx_usr(t_stat *file);
void	rwx_grp(t_stat *file);
void	rwx_oth(t_stat *file);

void	sort_list(t_list **list, char a);
void	check_first(t_list **list);
void	my_swap(t_list *dirent1, t_list *dirent2);
void	my_swapfirst(t_list **list, t_list *dirent1, t_list *dirent2);

void	rev_list(t_list **list);
void	rev_check_first(t_list **list);
void	sort_time(t_list **list);

#endif /* !MY_LS_H */
