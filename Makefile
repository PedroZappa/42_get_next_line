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

#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

MAKE	= make -C
SHELL	:= bash

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

UNAME 			= $(shell uname)

### Message Vars
_SUCCESS 		= [$(GRN)SUCCESS$(D)]
_INFO 			= [$(BLU)INFO$(D)]
_NORM 			= [$(MAG)Norminette$(D)]
_NORM_SUCCESS 	= $(GRN)=== OK:$(D)
_NORM_INFO 		= $(BLU)File no:$(D)
_NORM_ERR 		= $(RED)=== KO:$(D)
_SEP 			= =====================

#==============================================================================#
#                                    PATHS                                     #
#==============================================================================#

EXEC		= a.out
SRCB_PATH	= srcb
SRCLL_PATH	= srcll

SRC		= $(addprefix $(SRCB_PATH)/, get_next_line.c get_next_line_utils.c)
SRCB	= $(addprefix $(SRCB_PATH)/, get_next_line_bonus.c get_next_line_utils_bonus.c)
SRCLL	= $(addprefix $(SRCLL_PATH)/, get_next_line.c get_next_line_utils.c)

OBJS	= $(SRC:.c=.o)
OBJSB	= $(SRCB:.c=.o)
OBJSLL	= $(SRCLL:.c=.o)

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g
INC		= -I.

#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#

RM		= rm -f
AR		= ar rcs
MKDIR_P	= mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

##@ get_next_line Compilation Rules 🏗

all: $(OBJS)

.PHONY: gnl
gnl: $(OBJS)			## Compile Mandatory version
	@echo "\t$(YEL)Creating $(NAME) w/out bonus$(NC)"
	$(CC) $(CFLAGS) $(INC) main.c $(OBJS) -o $(EXEC)
	@echo "\t$(YEL)Getting .gdbinit for debugging$(NC)"
	cp srcb/.gdbinit .
	@echo "\n==> $(GRN)SUCCESS compiling gnl!$(NC) $(YEL)🖔$(NC)\n"

.PHONY: bonus
bonus: $(OBJSB)			## Compile Bonus version
	@echo "\t$(YEL)Creating $(NAME) w/ bonus$(NC)"
	$(CC) $(CFLAGS) $(INC) main.c $(OBJSB) -o $(EXEC)
	@echo "\t$(YEL)Getting .gdbinit for debugging$(NC)"
	cp srcb/.gdbinit .
	@echo "\n==> $(GRN)SUCCESS compiling gnl!$(NC) $(YEL)🖔$(NC)\n"

.PHONY: extrall
extrall: $(OBJSLL)		## Compile Linked Lists version
	@echo "\t$(YEL)Creating $(NAME) w/ Linked Lists w/out bonus$(NC)"
	$(CC) $(CFLAGS) $(INC) main.c $(OBJSLL) -o $(EXEC)
	@echo "\t$(YEL)Getting .gdbinit for debugging$(NC)"
	cp srcll/.gdbinit .
	@echo "\n==> $(GRN)SUCCESS compiling gnl!$(NC) $(YEL)🖔$(NC)\n"

##@ Clean-up Rules 󰃢

.PHONY: clean
clean:					## Remove object files
	@echo "\t$(RED)Cleaning objects 󰃢$(NC)"
	$(RM) $(OBJS) $(OBJSB) $(OBJSLL)
	@echo "\n==> $(GRN)Object files successfully removed!$(NC)\n"

.PHONY: fclean
fclean: clean			## Remove executable and .gdbinit
	@echo "\t$(RED)Cleaning executable 󰃢$(NC)"
	$(RM) $(EXEC)
	@echo "\t$(RED)Cleaning gdbinit 󰃢$(NC)"
	$(RM) .gdbinit
	@echo "\n==> $(GRN)$(NAME)Successfully removed!$(NC)\n"


##@ Help 󰛵

.PHONY: help
help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(NC)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-15s$(NC) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile
## Tweaked from source:
### https://www.padok.fr/en/blog/beautiful-makefile-awk

.PHONY: re
re: fclean all

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
