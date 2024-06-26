# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 11:39:41 by passunca          #+#    #+#              #
#    Updated: 2024/05/15 21:24:48 by passunca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  MAKE CONFIG                                 #
#==============================================================================#

MAKE	= make -C
SHELL	:= bash

# Default test values
FILES		= $(shell ls -l $(TESTS_PATH) | awk '{print $$9}')
ARG			?= "files/mini-vulf.txt"
COUNTER		:= 1
BUFFER_SIZE ?= 11
SIZES		:= 1 42 666
SIZES		+= 1600 3200 6400
SIZES		+= 12800 25600 51200
SIZES		+= 102400 204800 409600
SIZES		+= 10000000
# SIZES		+= -1

#==============================================================================#
#                                     NAMES                                    #
#==============================================================================#

UNAME 			= $(shell uname)
NAME 			= get_next_line
EXEC			= a.out

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

SRCB_PATH	= srcb
SRCLL_PATH	= srcll
LIBS_PATH	= lib
BUILD_PATH	= .build
TEMP_PATH	= .temp
TESTS_PATH	= files

SRC		= $(addprefix $(SRCB_PATH)/, get_next_line.c get_next_line_utils.c)
SRCB	= $(addprefix $(SRCB_PATH)/, get_next_line_bonus.c get_next_line_utils_bonus.c)
SRCLL	= $(addprefix $(SRCLL_PATH)/, get_next_line.c get_next_line_utils.c)

OBJS	= $(SRC:$(SRCB_PATH)/%.c=$(BUILD_PATH)/%.o)
OBJSB	= $(SRCB:$(SRCB_PATH)/%.c=$(BUILD_PATH)/%.o)
OBJSLL	= $(SRCLL:$(SRCLL_PATH)/%.c=$(BUILD_PATH)/%.o)

LIBFT_PATH	= $(LIBS_PATH)/libft
LIBFT_ARC	= $(LIBFT_PATH)/libft.a

GNLTESTER_PATH			= $(SRCB_PATH)/gnlTester
GNL_STATION_TESTER_PATH	= $(SRCB_PATH)/gnlStationTester

#==============================================================================#
#                              COMPILER & FLAGS                                #
#==============================================================================#

CC			= cc

CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -g
BFLAGS		?= -D BUFFER_SIZE=
INC			= -I.

#==============================================================================#
#                                COMMANDS                                      #
#==============================================================================#

RM		= rm -rf
AR		= ar rcs
MKDIR_P	= mkdir -p

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

##@ get_next_line Compilation Rules 🏗

all: $(BUILD_PATH) deps $(EXEC)	## Compile Mandatory version

$(EXEC): $(BUILD_PATH) $(OBJS) $(LIBFT_ARC) main.c			## Compile Mandatory version
	@echo "$(YEL)Compiling test for $(MAG)$(NAME)$(YEL) w/out bonus$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) $(BFLAGS)$(BUFFER_SIZE) main.c $(OBJS) $(LIBFT_ARC) -o $(EXEC)
	@echo "$(YEL)Linking $(CYA).gdbinit$(D) $(YEL)for debugging$(D)"
	@if test -f ".gdbinit"; then \
		unlink .gdbinit; \
	fi
	ln -s $(SRCB_PATH)/.gdbinit .gdbinit
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL)🖔$(D)]"
	make norm

bonus: $(BUILD_PATH) deps $(OBJSB) $(LIBFT_ARC) main.c		## Compile Bonus version
	@echo "$(YEL)Compiling test for $(MAG)$(NAME) $(YEL)w/ bonus$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) main.c $(OBJSB) $(LIBFT_ARC) -o $(EXEC)
	@echo "$(YEL)Linking $(CYA).gdbinit $(YEL)for debugging$(D)"
	@if test -f ".gdbinit"; then \
		unlink .gdbinit; \
	fi
	ln -s $(SRCB_PATH)/.gdbinit .gdbinit
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) w/ bonus $(YEL)🖔$(D)]"
	make norm

extrall: $(BUILD_PATH) deps $(OBJSLL) $(LIBFT_ARC) main.c	## Compile Linked Lists version
	@echo "$(YEL)Creating $(NAME) w/ Linked Lists w/out bonus$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) main.c $(OBJSLL) $(LIBFT_ARC) -o $(EXEC)
	@echo "$(YEL)Linking $(CYA).gdbinit $(YEL)for debugging$(D)"
	@if test -f ".gdbinit"; then \
		unlink .gdbinit; \
	fi
	ln -s $(SRCLL_PATH)/.gdbinit .gdbinit
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) w/ linked lists $(YEL)🖔$(D)]"
	make norm

deps:		## Download/Update libs
	@if test ! -d "$(LIBFT_PATH)"; then make get_libft; \
		else echo "$(YEL)[libft]$(D) folder found 🖔"; fi
	@echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"

-include $(BUILD_PATH)/%.d

$(BUILD_PATH)/%.o: $(SRCB_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) $(BFLAGS)$(BUFFER_SIZE) -MMD -MP -c $< -o $@

$(BUILD_PATH)/%.o: $(SRCLL_PATH)/%.c
	@echo -n "$(MAG)█$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) $(BFLAGS)$(BUFFER_SIZE) -MMD -MP -c $< -o $@

$(BUILD_PATH):
	$(MKDIR_P) $(BUILD_PATH)
	@echo "* $(YEL)Creating $(CYA)$(BUILD_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(TEMP_PATH):
	$(MKDIR_P) $(TEMP_PATH)
	@echo "* $(YEL)Creating $(CYA)$(TEMP_PATH)$(YEL) folder:$(D) $(_SUCCESS)"

$(LIBFT_ARC):
	$(MAKE) $(LIBFT_PATH) extra

get_libft:
	@echo "* $(CYA)Getting Libft submodule$(D)]"
	@if test ! -d "$(LIBFT_PATH)"; then \
		git clone git@github.com:PedroZappa/42_libft.git $(LIBFT_PATH); \
		echo "* $(GRN)Libft submodule download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)Libft submodule already exists 🖔"; \
	echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"; \
	fi

##@ Norm Rules

norm: $(TEMP_PATH)		## Run norminette test on source files
	@echo "$(CYA)$(_SEP)$(D)"
	@printf "${_NORM}: $(YEL)$(SRCB_PATH)$(D)\n"
	@ls $(SRCB_PATH) | wc -l > $(TEMP_PATH)/norm_ls.txt
	@printf "$(_NORM_INFO) $$(cat $(TEMP_PATH)/norm_ls.txt)\n"
	@printf "$(_NORM_SUCCESS) "
	@norminette $(SRCB_PATH) | grep -wc "OK" > $(TEMP_PATH)/norm.txt; \
	if [ $$? -eq 1 ]; then \
		echo "0" > $(TEMP_PATH)/norm.txt; \
	fi
	@printf "$$(cat $(TEMP_PATH)/norm.txt)\n"
	@if ! diff -q $(TEMP_PATH)/norm_ls.txt $(TEMP_PATH)/norm.txt > /dev/null; then \
		printf "$(_NORM_ERR) "; \
		norminette $(SRCB_PATH) | grep -v "OK"> $(TEMP_PATH)/norm_err.txt; \
		cat $(TEMP_PATH)/norm_err.txt | grep -wc "Error:" > $(TEMP_PATH)/norm_errn.txt; \
		printf "$$(cat $(TEMP_PATH)/norm_errn.txt)\n"; \
		printf "$$(cat $(TEMP_PATH)/norm_err.txt)\n"; \
	else \
		printf "[$(YEL)Everything is OK$(D)]\n"; \
	fi
	@echo "$(CYA)$(_SEP)$(D)"

check_ext_func: all		## Check for external functions
	@echo "[$(YEL)Checking for external functions$(D)]"
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "$(CYA)Reading binary$(D): $(MAG)$(NAME)$(D)"
	nm ./$(EXEC) | grep "U" | tee $(TEMP_PATH)/ext_func.txt
	@echo "$(YEL)$(_SEP)$(D)"

##@ Test Rules 🧪

test: deps $(EXEC)		## Test w/ default BUFFER_SIZE
	@TIMESTAMP=$(shell date +%Y%m%d%H%M%S); \
	if [ -f $(TEMP_PATH)/out.txt ]; then \
		mv -f $(TEMP_PATH)/out.txt $(TEMP_PATH)/out.$$TIMESTAMP.txt; \
	fi
	@for file in $(FILES); do \
		echo "Test $(MAG)$$COUNTER$(D) : Executing $(CYA)$$file$(D)" | tee -a $(TEMP_PATH)/out.txt; \
		valgrind --leak-check=full --show-leak-kinds=all --log-file=$(TEMP_PATH)/temp.txt ./$(EXEC) "$(TESTS_PATH)/$$file"; \
		sed -n '10p' $(TEMP_PATH)/temp.txt >> $(TEMP_PATH)/out.txt; \
		COUNTER=$$((COUNTER + 1)); \
		echo $$COUNTER > $(TEMP_PATH)/passed_count.txt; \
	done
	@make --no-print-directory test_results

test_stdin: deps $(EXEC) $(OBJS)	## Test w/ stdin
	@echo "$(YEL)Compiling $(CYA)stdin test$(D) for $(MAG)$(NAME)$(D)"
	$(CC) $(CFLAGS) $(BFLAGS)$(BUFFER_SIZE) $(DFLAGS) main_stdin.c $(OBJS) $(LIBFT_ARC) -o $(EXEC)
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) $(YEL)🖔$(D)]"
	make --no-print-directory norm
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC)

test_bonus: deps bonus $(TEMP_PATH) ## Test with multiple fds (bonus features)
	@if [ -f $(TEMP_PATH)/in_files.txt ]; then \
		$(RM) $(TEMP_PATH)/in_files.txt; \
	fi
	@echo "$(YEL)Creating file with all FILE paths...$(D)"
	@for file in $(FILES); do \
		printf "$(TESTS_PATH)/$$file" >> $(TEMP_PATH)/in_files.txt; \
		printf " " >> $(TEMP_PATH)/in_files.txt; \
	done
	@echo "$(YEL)Executing with files from in_files.txt$(D)"
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC) $(shell cat "$(TEMP_PATH)/in_files.txt")
	@echo "$(YEL)Executing with 2 files$(D)"
	valgrind --leak-check=full --show-leak-kinds=all ./$(EXEC) "$(TESTS_PATH)/mini-vulf.txt" "$(TESTS_PATH)/read_error.txt"

$(EXEC)_buffer: $(BUILD_PATH) $(OBJS) $(LIBFT_ARC) main.c
	@echo "$(YEL)Compiling test for $(MAG)$(NAME)$(YEL) with BUFFER_SIZE=$(BUFFER_SIZE)$(D)"
	$(CC) $(CFLAGS) $(DFLAGS) $(BFLAGS)$(BUFFER_SIZE) main.c $(OBJS) $(LIBFT_ARC) -o $(EXEC)
	@echo "[$(_SUCCESS) compiling $(MAG)$(NAME)$(D) with BUFFER_SIZE=$(BUFFER_SIZE) $(YEL)🖔$(D)]"

test_buffer: deps all $(TEMP_PATH)	## Test w/ different BUFFER_SIZEs
	@TIMESTAMP=$(shell date +%Y%m%d%H%M%S); \
	if [ -f $(TEMP_PATH)/out.txt ]; then \
		mv -f $(TEMP_PATH)/out.txt $(TEMP_PATH)/out.$$TIMESTAMP.txt; \
	fi
	@for size in $(SIZES); do \
		echo "$(YEL)$(_SEP)$(D)" | tee -a $(TEMP_PATH)/out.txt; \
		echo "for $(GRN)BUFFER_SIZE$(D) of : $(RED)$$size$(D)" | tee -a $(TEMP_PATH)/out.txt; \
		echo "$(YEL)$(_SEP)$(D)" | tee -a $(TEMP_PATH)/out.txt; \
		if [ -f $(EXEC) ]; then \
			$(RM) $(EXEC); \
			$(RM) $(OBJS); \
		fi; \
		sleep 0.3s; \
		make BUFFER_SIZE=$$size $(EXEC)_buffer; \
		for file in $(FILES); do \
			echo "$(YEL)$(_SEP)$(D)"; \
			echo "Test $(MAG)$$COUNTER$(D)" | tee -a $(TEMP_PATH)/out.txt; \
			echo "$(YEL)Current file: $(CYA)$$file$(D)" | tee -a $(TEMP_PATH)/out.txt; \
			if [ $$size -lt 0 ]; then \
				echo "read() with a BUFFER_SIZE smaller than 0 does not compile! Skipping Valgrind 🏇" | tee -a $(TEMP_PATH)/temp.txt; \
			else \
				valgrind --leak-check=full --show-leak-kinds=all --log-file=$(TEMP_PATH)/temp.txt ./$(EXEC) "$(TESTS_PATH)/$$file"; \
				sed -n '10p' $(TEMP_PATH)/temp.txt >> $(TEMP_PATH)/out.txt; \
			fi; \
			COUNTER=$$((COUNTER + 1)); \
			echo $$COUNTER > $(TEMP_PATH)/passed_count.txt; \
		done; \
	done
	@make --no-print-directory test_results

remove_ansi_noise:
	@sed -i 's/\//g' $(TEMP_PATH)/out.txt

test_results: $(TEMP_PATH)
	make --no-print-directory remove_ansi_noise
	@if command -v tmux; then \
		if command -v lnav; then \
			tmux split-window -h "lnav $(TEMP_PATH)/out.txt"; \
		else \
			tmux split-window -h "cat $(TEMP_PATH)/out.txt"; \
		fi; \
	else \
		tmux split-window -h "cat $(TEMP_PATH)/out.txt | sed 's/\x1b\[[0-9;]*m//g'"; \
	fi
	@echo "$(YEL)$(_SEP)$(D)"
	@echo "$(BCYA)Tests Summary$(D)"
	@TOTAL=$(shell cat $(TEMP_PATH)/passed_count.txt)
	@echo -ne "$(MAG)Total\t:  $(YEL)"
	@awk '{print $$1}' $(TEMP_PATH)/passed_count.txt
	@echo -ne "$(D)"
	@cat $(TEMP_PATH)/out.txt | grep heap | awk '{ print $$5, $$7 }' > $(TEMP_PATH)/count.txt
	@awk -v count=0 '{if ($$1 == $$2) count++} END \
		{ print "$(GRN)Passed$(D)\t: ", count}' $(TEMP_PATH)/count.txt
	@awk -v count=0 '{if ($$1 != $$2) \
		{ print $$1 > "$(TEMP_PATH)/failing_test_number.txt"; count++ }} END \
		{ print "$(RED)Failed$(D)\t: ", count}' $(TEMP_PATH)/count.txt
	@echo "$(YEL)$(_SEP)$(D)"

gnlTester: deps $(EXEC) get_gnlTester		## Run gnlTester
	tmux split-window -h "$(MAKE) $(GNLTESTER_PATH) a"
	tmux set-option remain-on-exit on

get_gnlTester:
	@echo "* $(CYA)Getting gnlTester submodule$(D)]"
	@if test ! -d "$(GNLTESTER_PATH)"; then \
		git clone git@github.com:Tripouille/gnlTester.git $(GNLTESTER_PATH); \
		echo "* $(GRN)gnlTester download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)gnlTester already exists 🖔"; \
		echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"; \
	fi

gnl-station-tester: deps $(EXEC) get_gnlStationTester			## Run gnl-station-tester
	tmux split-window -h "$(MAKE) $(GNL_STATION_TESTER_PATH)"
	tmux set-option remain-on-exit on

get_gnlStationTester:
	@echo "* $(CYA)Getting gnlStationTester submodule$(D)]"
	@if test ! -d "$(GNL_STATION_TESTER_PATH)"; then \
		git clone git@github.com:kodpe/gnl-station-tester.git $(GNL_STATION_TESTER_PATH); \
		echo "* $(GRN)gnl-station-tester download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)gnl-station-tester already exists 🖔"; \
		echo " $(RED)$(D) [$(GRN)Running tester!$(D)]"; \
	fi

##@ Debug Rules 

gdb: deps $(EXEC) $(TEMP_PATH)			## Debug w/ gdb
	tmux split-window -h "gdb --tui --args ./$(EXEC) 'files/mini-vulf.txt'"
	tmux resize-pane -L 5
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

vgdb: deps $(EXEC) $(TEMP_PATH)			## Debug w/ valgrind & gdb
	tmux split-window -h "valgrind --vgdb-error=0 --log-file=gdb.txt ./$(EXEC) $(ARG)"
	make vgdb_pid
	tmux split-window -v "gdb --tui -x $(TEMP_PATH)/gdb_commands.txt $(EXEC)"
	tmux resize-pane -U 18
	touch gdb.txt
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

vgdb_bonus: deps $(EXEC) $(TEMP_PATH)			## Debug bonus w/ valgrind & gdb
	tmux split-window -h "valgrind --vgdb-error=0 --log-file=gdb.txt ./$(EXEC) '$(TESTS_PATH)/mini-vulf.txt' '$(TESTS_PATH)/read_error.txt'"
	make vgdb_pid
	tmux split-window -v "gdb --tui -x $(TEMP_PATH)/gdb_commands.txt $(EXEC)"
	tmux resize-pane -U 18
	touch gdb.txt
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

vgdb_pid: $(EXEC) $(TEMP_PATH)
	printf "target remote | vgdb --pid=" > $(TEMP_PATH)/gdb_commands.txt
	printf "$(shell pgrep -f valgrind)" >> $(TEMP_PATH)/gdb_commands.txt

##@ Clean-up Rules 󰃢

clean: 				## Remove object files
	@echo "*** $(YEL)Removing $(MAG)$(NAME)$(D) and deps $(YEL)object files$(D)"
	@if [ -d "$(BUILD_PATH)" ] || [ -d "$(TEMP_PATH)" ] || [ -d "$(GNLTESTER_PATH)" ]; then \
		if [ -d "$(BUILD_PATH)" ]; then \
			$(RM) $(BUILD_PATH); \
			echo "* $(YEL)Removing $(CYA)$(BUILD_PATH)$(D) folder & files$(D): $(_SUCCESS)"; \
		fi; \
		if [ -d "$(TEMP_PATH)" ]; then \
			$(RM) $(TEMP_PATH); \
			echo "* $(YEL)Removing $(CYA)$(TEMP_PATH)$(D) folder & files:$(D) $(_SUCCESS)"; \
		fi; \
		if [ -d "$(GNLTESTER_PATH)" ]; then \
			$(RM) $(GNLTESTER_PATH); \
			echo "* $(YEL)Removing $(CYA)$(GNLTESTER_PATH)$(D) folder & files:$(D) $(_SUCCESS)"; \
		fi; \
		if [ -d "$(GNL_STATION_TESTER_PATH)" ]; then \
			$(RM) $(GNL_STATION_TESTER_PATH); \
			echo "* $(YEL)Removing $(CYA)$(GNL_STATION_TESTER_PATH)$(D) folder & files:$(D) $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to clean!$(D)]"; \
	fi

fclean: clean			## Remove executable and .gdbinit
	@if [ -f ".gdbinit" ] || [ -f "$(EXEC)" ]; then \
		if [ -f "$(EXEC)" ]; then \
			$(RM) $(EXEC); \
			echo "* $(YEL)Removing $(CYA)$(EXEC)$(D) file: $(_SUCCESS)"; \
		fi; \
		if [ -f ".gdbinit" ]; then \
			$(RM) .gdbinit; \
			echo "* $(YEL)Removing $(CYA).gdbinit$(D) file: $(_SUCCESS)"; \
		fi; \
	else \
		echo " $(RED)$(D) [$(GRN)Nothing to be fcleaned!$(D)]"; \
	fi

libclean: fclean	## Remove libs
	$(RM) $(LIBS_PATH)
	@echo "* $(YEL)Removing lib folder & files!$(D) : $(_SUCCESS)"

re: fclean all	## Purge & Recompile

##@ Help 󰛵

help: 			## Display this help page
	@awk 'BEGIN {FS = ":.*##"; \
			printf "\n=> Usage:\n\tmake $(GRN)<target>$(D)\n"} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "\t$(GRN)%-18s$(D) %s\n", $$1, $$2 } \
		/^##@/ { \
			printf "\n=> %s\n", substr($$0, 5) } ' Makefile
## Tweaked from source:
### https://www.padok.fr/en/blog/beautiful-makefile-awk

.PHONY: bonus extrall clean fclean re help

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
