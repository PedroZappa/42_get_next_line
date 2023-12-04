# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 11:39:41 by passunca          #+#    #+#              #
#    Updated: 2023/11/25 18:01:22 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libgnl.a

SRCB_PATH	= srcb
SRCLL_PATH	= srcll

SRC		= srcb/get_next_line.c srcb/get_next_line_utils.c
SRCB	= srcb/get_next_line_bonus.c srcb/get_next_line_utils_bonus.c
SRCLL	= srcll/get_next_line.c srcll/get_next_line_utils.c

SRC		= $(SRCB_PATH)/get_next_line.c $(SRCB_PATH)/get_next_line_utils.c
SRCB	= $(SRCB_PATH)/get_next_line_bonus.c $(SRCB_PATH)/get_next_line_utils_bonus.c
SRCLL	= $(SRCLL_PATH)/get_next_line.c $(SRCLL_PATH)/get_next_line_utils.c

OBJS	= $(SRC:.c=.o)
OBJSB	= $(SRCB:.c=.o)
OBJSLL	= $(SRCLL:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
INC		= -I.
RM		= rm -f
AR		= ar rcs

all: $(NAME)

$(OBJS): %.o: %.c
	@echo "\nCompiling $<, Mandatory version\n"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRCB_PATH)

$(OBJSB): %.o: %.c
	@echo "\nCompiling $<, Bonus version\n"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRCB_PATH)

$(OBJSLL): %.o: %.c
	@echo "\nCompiling $<, Linked Lists version\n"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(SRCLL_PATH)

$(NAME): $(OBJS)
	@echo "Creating $(NAME) w/out bonus\n"
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJSB)
	@echo "\nCreating $(NAME) w/ bonus"
	$(AR) $(NAME) $(OBJSB)

extrall: $(OBJSLL)
	@echo "Creating $(NAME) w/ Linked Lists w/out bonus\n"
	$(AR) $(NAME) $(OBJSLL)

clean:
	@echo "Cleaning objects\n"
	$(RM) $(OBJS) $(OBJSB) $(OBJSLL)

fclean: clean
	@echo "Cleaning $(NAME)\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus extrall clean fclean re
