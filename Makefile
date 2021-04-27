# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 11:09:40 by edjavid           #+#    #+#              #
#    Updated: 2021/04/24 11:43:47 by edjavid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_treat_char.c \
	   ft_treat_int.c \
	   ft_treat_pointer.c \
	   ft_treat_string.c \
	   ft_treat_unsigned.c \
	   ft_treat_width.c \
	   ft_treat_x.c \


SURO = ft_printf.o \
	   ft_treat.char.o \
	   ft_treat_int.o \
	   ft_treat_pointer.o \
	   ft_treat_string.o \
	   ft_treat_unsigned.o \
	   ft_treat_width.o \
	   ft_treat_x.o \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) ft_printf.h $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(SURO)
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
