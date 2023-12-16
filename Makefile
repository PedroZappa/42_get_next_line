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

#####################
### Names & Paths ###
#####################

EXEC	= a.out
SRCB_PATH	= srcb
SRCLL_PATH	= srcll

SRC		= $(addprefix $(SRCB_PATH)/, get_next_line.c get_next_line_utils.c)
SRCB	= $(addprefix $(SRCB_PATH)/, get_next_line_bonus.c get_next_line_utils_bonus.c)
SRCLL	= $(addprefix $(SRCLL_PATH)/, get_next_line.c get_next_line_utils.c)

OBJS	= $(SRC:.c=.o)
OBJSB	= $(SRCB:.c=.o)
OBJSLL	= $(SRCLL:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
INC		= -I.
RM		= rm -f
AR		= ar rcs


################
### Rules ###
################

##@ Help 󰛵

.PHONY: help
help: 			## Show help
	@awk 'BEGIN {FS = ":.*##"; \
		printf "\nUsage:\n  make $(GRN)<target>$(NC)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
		printf "  $(GRN)%-15s$(NC) %s\n", $$1, $$2 } \
		/^##@/ { \
		printf "\n$(NC)%s$(GRN)\n", substr($$0, 5) } ' Makefile

##@ get_next_line Compilation Rules 🏗

all: $(NAME)

.PHONY: gnl
gnl: $(OBJS)			## Compile Mandatory version
	@echo "\t$(YEL)Creating $(NAME) w/out bonus$(NC)"
	$(CC) $(CFLAGS) $(INC) main.c $(OBJS) -o $(EXEC)
	@echo "==> $(GRN)SUCCESS compiling gnl!$(NC) $(YEL)🖔$(NC)\n"

.PHONY: bonus
bonus: $(OBJSB)			## Compile Bonus version
	@echo "\t$(YEL)Creating $(NAME) w/ bonus$(NC)"
	$(CC) $(CFLAGS) $(INC) main.c $(OBJSB) -o $(EXEC)
	@echo "==> $(GRN)SUCCESS compiling gnl!$(NC) $(YEL)🖔$(NC)\n"

.PHONY: extrall
extrall: $(OBJSLL)		## Compile Linked Lists version
	@echo "\t$(YEL)Creating $(NAME) w/ Linked Lists w/out bonus$(NC)"
	$(CC) $(CFLAGS) $(INC) main.c $(OBJSLL) -o $(EXEC)
	@echo "==> $(GRN)SUCCESS compiling gnl!$(NC) $(YEL)🖔$(NC)\n"

##@ Clean-up Rules 󰃢

.PHONY: clean
clean:					## Remove object files
	@echo "\t$(RED)Cleaning objects 󰃢$(NC)"
	$(RM) $(OBJS) $(OBJSB) $(OBJSLL)
	@echo "==> $(GRN)Object files successfully removed!$(NC)\n"

.PHONY: fclean
fclean: clean			## Remove executable
	@echo "\t$(RED)Cleaning executable 󰃢$(NC)"
	$(RM) $(EXEC)
	@echo "==> $(GRN)$(NAME)Successfully removed!$(NC)\n"

.PHONY: re
re: fclean all


########################
### ANSI Color Codes ###
########################

# Regular text
BLK = \033[0;30m
RED = \033[0;31m
GRN = \033[0;32m
YEL = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYN = \033[0;36m
WHT = \033[0;37m

# Regular bold text
BBLK = \033[1;30m
BRED = \033[1;31m
BGRN = \033[1;32m
BYEL = \033[1;33m
BBLU = \033[1;34m
BMAG = \033[1;35m
BCYN = \033[1;36m
BWHT = \033[1;37m

# Regular underline text
UBLK = \033[4;30m
URED = \033[4;31m
UGRN = \033[4;32m
UYEL = \033[4;33m
UBLU = \033[4;34m
UMAG = \033[4;35m
UCYN = \033[4;36m
UWHT = \033[4;37m

# Regular background
BLKB = \033[40m
REDB = \033[41m
GRNB = \033[42m
YELB = \033[43m
BLUB = \033[44m
MAGB = \033[45m
CYNB = \033[46m
WHTB = \033[47m

# High intensity background 
BLKHB = \033[0;100m
REDHB = \033[0;101m
GRNHB = \033[0;102m
YELHB = \033[0;103m
BLUHB = \033[0;104m
MAGHB = \033[0;105m
CYNHB = \033[0;106m
WHTHB = \033[0;107m

# High intensity text
HBLK = \033[0;90m
HRED = \033[0;91m
HGRN = \033[0;92m
HYEL = \033[0;93m
HBLU = \033[0;94m
HMAG = \033[0;95m
HCYN = \033[0;96m
HWHT = \033[0;97m

# Bold high intensity text
BHBLK = \033[1;90m
BHRED = \033[1;91m
BHGRN = \033[1;92m
BHYEL = \033[1;93m
BHBLU = \033[1;94m
BHMAG = \033[1;95m
BHCYN = \033[1;96m
BHWHT = \033[1;97m

# Reset
NC=\033[0m

