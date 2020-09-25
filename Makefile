# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 19:34:36 by nayache           #+#    #+#              #
#    Updated: 2019/10/16 19:04:33 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

SRCS		= 		ft_itoa.c ft_memcmp.c ft_strdup.c ft_strtrim.c \
				ft_atoi.c ft_memcpy.c ft_strjoin.c ft_substr.c \
				ft_bzero.c ft_memset.c ft_strlcat.c ft_tolower.c \
				ft_calloc.c ft_putchar_fd.c ft_strlcpy.c ft_toupper.c \
				ft_isalnum.c ft_putendl_fd.c ft_strlen.c ft_memmove.c\
				ft_isalpha.c ft_putnbr_fd.c ft_strmapi.c ft_strcpy.c \
				ft_isascii.c ft_putstr_fd.c ft_putstr.c ft_strncmp.c \
				ft_strstr.c ft_putchar.c ft_strcmp.c \
				ft_isdigit.c ft_memccpy.c ft_split.c ft_strnstr.c \
				ft_isprint.c ft_memchr.c ft_strchr.c ft_strrchr.c \
	
OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) :	${OBJS} 
	ar rc ${NAME} ${OBJS}

all :		${NAME}

clean :
		${RM} ${OBJS}

fclean :	clean
		${RM} ${NAME}

re :		fclean all
