# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:00:32 by dajeon            #+#    #+#              #
#    Updated: 2023/06/03 13:24:45 by dajeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out
SOURCES = main.c

LIB = ft
LIB_DIR = ..

# **************************************************************************** #

SRCS = $(SOURCES)
OBJS = $(SOURCES:.c=.o)
LDLIBS = -l $(LIB)

# **************************************************************************** #

MAKE = make
CC = gcc
AR = ar
RM = rm

CFLAGS = -Wall -Wextra -Werror
ARFLAGS = crus
RMFLAGS = -rf

LDFLAGS = -L $(LIB_DIR)

# Commands ******************************************************************* #

all : $(NAME)
	./a.out

clean :
	$(RM) $(RMFLAGS) 

fclean : 
	$(MAKE) clean
	$(RM) $(RMFLAGS) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

# Dependency ***************************************************************** #

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LDFLAGS) $(LDLIBS)

# **************************************************************************** #

