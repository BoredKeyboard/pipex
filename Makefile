# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mforstho <mforstho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/09/27 15:13:27 by mforstho      #+#    #+#                  #
#    Updated: 2022/09/27 15:14:02 by mforstho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := pipex
CC := gcc
CFLAGS ?= -Wextra -Wall -Werror

SOURCES :=									\
	src/pipex.c

HEADERS := src/pipex.h libft/libft.h
OBJDIR := obj
OBJECTS := $(addprefix $(OBJDIR)/, $(SOURCES:c=o))

LIBFLAGS := -L libft -l ft -l glfw3 -framework Cocoa -framework OpenGL -framework IOKit

LIBFT := libft/libft.a

INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))
CFLAGS += $(INCLUDES)

all : $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(dir $(LIBFT))

clean :
	rm -rf $(OBJDIR)
	$(MAKE) -C $(dir $(LIBFT)) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(dir $(LIBFT)) fclean

re : fclean all

.PHONY : all clean fclean re
