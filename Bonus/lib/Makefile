##
## Makefile for  in /home/BISHOP/delivery/CPool_bistro-matic/lib/my
## 
## Made by Benjamin GAYMAY
## Login   <benjamin.g@epitech.net>
## 
## Started on  Thu Nov  3 14:59:33 2016 Benjamin GAYMAY
## Last update Thu Dec  1 10:34:40 2016 Benjamin GAYMAY
##

SRCS	=	./my/my_putchar.c \
		./my/my_getnbr.c \
		./my/my_put_nbr.c \
		./my/my_putstr.c \
		./my/my_revstr.c \
		./my/my_strlen.c \
		./my/my_strncat.c \
		./my/my_strcmp.c \
		./my_printf/flag.c \
		./my_printf/hexa.c \
		./my_printf/my_printf.c \
		./my_printf/my_putchar.c \
		./my_printf/my_put_nbr.c \
		./my_printf/my_put_nbr_unsigned.c \
		./my_printf/my_putstr.c \
		./my_printf/my_strlen.c \
		./my_printf/octal_bin.c

RM	=	rm -rf

NAME	=	libmy.a

OBJS	=	$(SRCS:.c=.o)

AC	=	ar rc

$(NAME): $(OBJS)
	$(AC) $(NAME) $(OBJS)
	ranlib $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

