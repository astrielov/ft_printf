# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 20:54:44 by astrielov         #+#    #+#              #
#    Updated: 2018/03/30 13:09:00 by astrelov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRJDIR = $(PWD)

SRCS =	src/ft_printf.c \
		src/parse/flags.c \
		src/parse/parse.c \
		src/parse/width.c \
		src/parse/precision.c \
		src/parse/length.c \
		src/handle/handle.c \
		src/handle/number.c \
		src/handle/char.c \
		src/handle/wchar.c \
		src/handle/string.c \
		src/handle/pointer.c \
		src/handle/wstring.c \
		src/handle/integer/integer.c \
		src/handle/integer/octal.c \
		src/handle/integer/decimal.c \
		src/handle/integer/hexademical.c \
		src/helpers/buffer.c \
		src/helpers/push_chars.c \
		src/libft/ft_atoi.c \
		src/libft/ft_bzero.c \
		src/libft/ft_d_bblsort.c \
		src/libft/ft_d_minind.c \
		src/libft/ft_d_sqrt.c \
		src/libft/ft_errmsg.c \
		src/libft/ft_gnl.c \
		src/libft/ft_isalnum.c \
		src/libft/ft_isalpha.c \
		src/libft/ft_isascii.c \
		src/libft/ft_isdigit.c \
		src/libft/ft_isprint.c \
		src/libft/ft_itoa.c \
		src/libft/ft_lf_pow.c \
		src/libft/ft_ll_fact.c \
		src/libft/ft_lstadd.c \
		src/libft/ft_lstdel.c \
		src/libft/ft_lstdelone.c \
		src/libft/ft_lstiter.c \
		src/libft/ft_lstmap.c \
		src/libft/ft_lstnew.c \
		src/libft/ft_memalloc.c \
		src/libft/ft_memccpy.c \
		src/libft/ft_memchr.c \
		src/libft/ft_memcmp.c \
		src/libft/ft_memcpy.c \
		src/libft/ft_memdel.c \
		src/libft/ft_memmove.c \
		src/libft/ft_memset.c \
		src/libft/ft_putchar.c \
		src/libft/ft_putchar_fd.c \
		src/libft/ft_putendl.c \
		src/libft/ft_putendl_fd.c \
		src/libft/ft_putnbr.c \
		src/libft/ft_putnbr_fd.c \
		src/libft/ft_putnstr.c \
		src/libft/ft_putstr.c \
		src/libft/ft_putstr_fd.c \
		src/libft/ft_strcat.c \
		src/libft/ft_strchr.c \
		src/libft/ft_strclr.c \
		src/libft/ft_strcmp.c \
		src/libft/ft_strcpy.c \
		src/libft/ft_strdel.c \
		src/libft/ft_strdup.c \
		src/libft/ft_strequ.c \
		src/libft/ft_striter.c \
		src/libft/ft_striteri.c \
		src/libft/ft_strjoin.c \
		src/libft/ft_strlcat.c \
		src/libft/ft_strlen.c \
		src/libft/ft_strmap.c \
		src/libft/ft_strmapi.c \
		src/libft/ft_strncat.c \
		src/libft/ft_strncmp.c \
		src/libft/ft_strncpy.c \
		src/libft/ft_strnequ.c \
		src/libft/ft_strnew.c \
		src/libft/ft_strnstr.c \
		src/libft/ft_strpbrk.c \
		src/libft/ft_strrchr.c \
		src/libft/ft_strsplit.c \
		src/libft/ft_strstr.c \
		src/libft/ft_strsub.c \
		src/libft/ft_strtolow.c \
		src/libft/ft_strtoupp.c \
		src/libft/ft_strtrim.c \
		src/libft/ft_tolower.c \
		src/libft/ft_toupper.c

CFLAGS = -Wall -Wextra -Werror

HEADERS = -I ./includes

OBJDIR = obj/

OBJS = $(patsubst src/%.c, $(OBJDIR)%.o, $(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
		@ar rc $(NAME) $(OBJS)
		@printf "\033[0;32mlibftprintf.a: DONE\033[0m\n"

$(OBJS): | obj

obj:
		@mkdir -p $(OBJDIR)/libft
		@mkdir -p $(OBJDIR)/parse
		@mkdir -p $(OBJDIR)/handle/integer
		@mkdir -p $(OBJDIR)/helpers

$(OBJDIR)%.o: src/%.c
				@gcc $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	   		@rm -rf $(OBJS)
	   		@rm -rf $(OBJDIR)
			@printf "\033[0;32mlibftprintf objects: removed\033[0m\n"

fclean:			clean
	    	@rm -f $(NAME)
			@printf "\033[0;32mlibftprintf.a: removed\033[0m\n"

re:	            fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
