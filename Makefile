# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xredm <xredm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 15:25:48 by xredm             #+#    #+#              #
#    Updated: 2023/05/15 21:31:10 by xredm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
CC = cc
FLAGS = -g -Wall -Wextra -Werror
RM = rm -f
HEADER = ./include/push_swap.h
LIBFT_FILE = ./libft/libft.a
LIBFT_LOC = ./libft/
SRCS = $(wildcard ./src/*.c) 
BONUS_SRCS = $(wildcard ./src/checker/*.c)

# Lets add some color
CYAN := CYAN := \033[0;36m
MAGENTA := \033[0;35m
YELLOW := \033[0;33m
RED := \033[0;31m
GREEN := \033[0;32m
BLUE := \033[0;34m
BOLD := \033[1m
RESET := \033[0m

all: $(NAME)

$(NAME): $(LIBFT_FILE)
	$(CC) $(FLAGS) $(SRCS) $(LIBFT_FILE) -o $(NAME)
	@echo "													    "
	@echo "$(CYAN)<3----------------------------------<3$(RESET)"
	@echo "$(CYAN)         -------------------          $(RESET)"
	@echo "$(MAGENTA)$(BOLD)The $(NAME) is succesfully created!$(RESET)"
	@echo "$(CYAN)         -------------------          $(RESET)"
	@echo "$(CYAN)<3----------------------------------<3$(RESET)"
	@echo "												 	   "

bonus: $(LIBFT_FILE)
	$(CC) $(FLAGS) $(BONUS_SRCS) $(LIBFT_FILE) -o $(BONUS)
	@echo "													    "
	@echo "$(MAGENTA)===================================$(RESET)"
	@echo "$(MAGENTA)      -------------------          $(RESET)"
	@echo "$(YELLOW)$(BOLD)The $(BONUS) is also doing alright!$(RESET)"
	@echo "$(MAGENTA)      -------------------          $(RESET)"
	@echo "$(MAGENTA)===================================$(RESET)"
	@echo "												 	    "

$(LIBFT_FILE):
	@make -C $(LIBFT_LOC) all bonus --no-print-directory
	@echo "													    "
	@echo "$(YELLOW)************************************$(RESET)"
	@echo "$(YELLOW)------------------------------------$(RESET)"
	@echo "$(YELLOW)------------------------------------$(RESET)"
	@echo "$(YELLOW)------------------------------------$(RESET)"
	@echo "$(RED)$(BOLD)	LIBFT is ready to use!$(RESET)"
	@echo "$(YELLOW)------------------------------------$(RESET)"
	@echo "$(YELLOW)------------------------------------$(RESET)"
	@echo "$(YELLOW)------------------------------------$(RESET)"
	@echo "$(YELLOW)************************************$(RESET)"
	@echo "												 	    "

libft: $(LIBFT_FILE)

clean:
	@$(RM) $(NAME) $(BONUS)
	@make -C $(LIBFT_LOC) clean --no-print-directory
	@echo "													    "
	@echo "$(RED)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(RESET)"
	@echo "$(RED)---------------------------------------$(RESET)"
	@echo "$(RED)---------------------------------------$(RESET)"
	@echo "$(BLUE)$(BOLD)Wait a sec...Working on it.........$(RESET)"
	@echo "$(RED)---------------------------------------$(RESET)"
	@echo "$(RED)---------------------------------------$(RESET)"
	@echo "$(RED)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~$(RESET)"
	@echo "												 	    "

fclean: clean
	@make -C $(LIBFT_LOC) fclean --no-print-directory
	@echo "												 	    "
	@echo "$(BLUE)^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$(RESET)"
	@echo "$(BLUE)--------------------------------------$(RESET)"
	@echo "$(BLUE)--------------------------------------$(RESET)"
	@echo "$(GREEN)$(BOLD).......It is clean now.............$(RESET)"
	@echo "$(BLUE)--------------------------------------$(RESET)"
	@echo "$(BLUE)--------------------------------------$(RESET)"
	@echo "$(BLUE)^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^$(RESET)"
	@echo "												 	    "

re: clean all

.PHONY: all clean fclean re
