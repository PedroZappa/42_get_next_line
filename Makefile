# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 11:39:41 by passunca          #+#    #+#              #
#    Updated: 2023/11/25 12:10:22 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRC		= srcb/get_next_line.c srcb/get_next_line_utils.c
SRCB	= srcb/get_next_line_bonus.c srcb/get_next_line_utils_bonus.c
SRCLL	= srcll/get_next_line.c srcll/get_next_line_utils.c

OBJS = $(SRC:.c=.o)
OBJSB = $(SRCB:.c=.o)
OBJSLL = $(SRCLL:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = -I.
RM = rm -f
AR = ar rcs

all: $(NAME)

.o:.c:
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	@echo "Creating $(NAME) w/out bonus"
	$(AR) $(NAME) $(OBJS) srcb/get_next_line.h

bonus: $(OBJSB)
	@echo "Creating $(NAME) w/ bonus"
	$(AR) $(NAME) $(OBJSB)

extrall: $(OBJSLL)
	@echo "Creating $(NAME) w/ Linked Lists w/out bonus"
	$(AR) $(NAME) $(OBJSLL)

clean:
	@echo "Cleaning objects"
	$(RM) $(OBJS) $(OBJSB) $(OBJSLL)

fclean: clean
	@echo "Cleaning $(NAME)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus extrall clean fclean re
