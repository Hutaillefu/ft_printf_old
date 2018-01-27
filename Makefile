# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: htaillef <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/05 18:54:15 by htaillef     #+#   ##    ##    #+#        #
#    Updated: 2017/12/12 16:34:16 by htaillef    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_SRCS = 	srcs/libft/ft_putchar_fd.c	\
				srcs/libft/ft_putchar.c		\
				srcs/libft/ft_putstr_fd.c	\
				srcs/libft/ft_putstr.c		\
				srcs/libft/ft_putnbr_fd.c	\
				srcs/libft/ft_putnbr.c		\
				srcs/libft/ft_isdigit.c		\
				srcs/libft/ft_atoi.c		\
				srcs/libft/ft_strdup.c		\
				srcs/libft/ft_strcpy.c		\
				srcs/libft/ft_strsub.c		\
				srcs/libft/ft_strlen.c		\
				srcs/libft/ft_strcmp.c		\
				srcs/libft/ft_memalloc.c	\
				srcs/libft/ft_strjoin.c		\
				srcs/libft/ft_bzero.c		\
				srcs/libft/ft_strcat.c		\
				srcs/libft/ft_strncat.c		\
				srcs/libft/ft_itoall.c		\
				srcs/libft/ft_itoaull.c		\
				srcs/libft/ft_strncmp.c

PRINTF_SRCS = 	srcs/ft_printf.c			\
				srcs/display.c				\
				srcs/struct_manager.c		\
				srcs/str_manip.c			\
				srcs/extractor.c			\
				srcs/ft_strnjoin.c			\
				srcs/ft_itoall_base.c		\
				srcs/ft_itoaull_base.c
		
HEADERS = ./includes

PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o : %.c
	@gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(LIBFT_OBJS) $(PRINTF_OBJS)
	@ar -rcs $(NAME) $(LIBFT_OBJS) $(PRINTF_OBJS)

clean :
	@rm -rf $(LIBFT_OBJS) $(PRINTF_OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
