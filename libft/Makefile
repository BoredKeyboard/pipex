# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mforstho <mforstho@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/12 16:16:58 by mforstho      #+#    #+#                  #
#    Updated: 2022/09/14 14:40:04 by mforstho      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := gcc
CFLAGS ?= -Wextra -Wall -Werror

CHAR_SOURCES :=						\
	src/char/ft_isalnum.c			\
	src/char/ft_isalpha.c			\
	src/char/ft_isascii.c			\
	src/char/ft_isdigit.c			\
	src/char/ft_isprint.c			\
	src/char/ft_tolower.c			\
	src/char/ft_toupper.c			\
	src/char/ft_isspace.c


IO_SOURCES :=						\
	src/io/ft_putchar_fd.c			\
	src/io/ft_putendl_fd.c			\
	src/io/ft_putnbr_fd.c			\
	src/io/ft_putnbr_u_base_fd.c	\
	src/io/ft_putnbr_u_fd.c			\
	src/io/ft_putstr_fd.c


# LST_SOURCES :=						\
# 	src/lst/ft_lstadd_back_bonus.c	\
# 	src/lst/ft_lstadd_front_bonus.c	\
# 	src/lst/ft_lstclear_bonus.c		\
# 	src/lst/ft_lstdelone_bonus.c	\
# 	src/lst/ft_lstiter_bonus.c		\
# 	src/lst/ft_lstlast_bonus.c		\
# 	src/lst/ft_lstmap_bonus.c		\
# 	src/lst/ft_lstnew_bonus.c		\
# 	src/lst/ft_lstsize_bonus.c		\
# 	src/lst/ft_lstnew_back.c


MEM_SOURCES :=						\
	src/mem/ft_bzero.c				\
	src/mem/ft_calloc.c				\
	src/mem/ft_memchr.c				\
	src/mem/ft_memcmp.c				\
	src/mem/ft_memcpy.c				\
	src/mem/ft_memmove.c			\
	src/mem/ft_memset.c


NBR_SOURCES :=						\
	src/nbr/calc_power_u_base.c		\
	src/nbr/count_digits_base.c		\
	src/nbr/count_digits_u_base.c	\
	src/nbr/ft_atoi.c				\
	src/nbr/ft_itoa.c


STR_SOURCES :=						\
	src/str/ft_split.c				\
	src/str/ft_strchr.c				\
	src/str/ft_strdup.c				\
	src/str/ft_striteri.c			\
	src/str/ft_strjoin.c			\
	src/str/ft_strlcat.c			\
	src/str/ft_strlcpy.c			\
	src/str/ft_strlen.c				\
	src/str/ft_strmapi.c			\
	src/str/ft_strncmp.c			\
	src/str/ft_strnstr.c			\
	src/str/ft_strrchr.c			\
	src/str/ft_strtrim.c			\
	src/str/ft_substr.c

SOURCES := $(CHAR_SOURCES) $(IO_SOURCES) $(LST_SOURCES) $(MEM_SOURCES) $(NBR_SOURCES) $(STR_SOURCES)

HEADERS := libft.h
OBJDIR := obj
OBJECTS := $(addprefix $(OBJDIR)/, $(SOURCES:c=o))

INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))
CFLAGS += $(INCLUDES)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $^

$(OBJDIR)/%.o : %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
