##
## Makefile for Makefile in /home/benjamin.g/save/nouveau_projet
## 
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
## 
## Started on  Sun Nov 20 13:42:20 2016 Benjamin GAYMAY
## Last update Thu Dec  1 12:24:00 2016 Benjamin GAYMAY
##

CC	=	gcc

RM	=	rm -f

NAME	=	my_ls

LIB	=	-L./lib/ -lmy

CFLAGS	+=	-I./include

SRCS	=	main.c \
		use_list.c \
		sort_list.c \
		my_ls.c \
		check_flag.c \
		r_flag.c \
		l_flag.c \
		t_flag.c \
		flag.c \
		rwx.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./lib/
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./lib/

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./lib/

re: fclean all

.PHONY:	all clean fclean re cleanlib fcleanlib
