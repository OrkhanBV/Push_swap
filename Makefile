# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jremarqu <jremarqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/11 20:30:59 by jremarqu          #+#    #+#              #
#    Updated: 2020/03/13 23:05:11 by jremarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, lib_refresh

# =========== #
# PUSH_SWAP	  #
# =========== #

PUSH_SWAP_NAME = push_swap

PUSH_SWAP_OBJ_DIR = ./objects/push_swap/

PUSH_SWAP_SRC = $(addprefix $(SRC), $(PUSH_SWAP_SRC_NAME))
PUSH_SWAP_OBJ = $(addprefix $(PUSH_SWAP_OBJ_DIR), $(PUSH_SWAP_OBJ_NAME))

# =========== #
# CHECKER	  #
# =========== #

CHECKER_NAME = checker

CHECKER_OBJ_DIR = ./objects/checker/

CHECKER_SRC = $(addprefix $(SRC), $(CHECKER_SRC_NAME))
CHECKER_OBJ = $(addprefix $(CHECKER_OBJ_DIR), $(CHECKER_OBJ_NAME))

# =========== #
#   OTHER	  #
# =========== #

SRC = ./source/

OBJ_DIR = ./objects/

# =========== #
#	INCLUDES  #
# =========== #

INCLUDES_FILES_LIST =					\
				header.h				\

INCLUDES_DIR = 	./includes/

INCLUDES_FILES = $(addprefix $(INCLUDES_DIR), $(INCLUDES_FILES_LIST))

# =========== #
# 	LIBFT	  #
# =========== #

LIBFT_DIR =						\
	./includes/libft/			\

PUSH_SWAP_SRC_NAME = 			\
	action_ch_part_four.c		\
	action_ch_part_one.c		\
	action_ch_part_three.c		\
	action_ch_part_two.c		\
	actions_part_four.c			\
	actions_part_one.c			\
	actions_part_three.c		\
	actions_part_two.c			\
	algo_manager.c				\
	algo_math.c					\
	algoritm_main_part.c		\
	check_order.c				\
	checker.c					\
	finish_stack_a.c			\
	for_algoritm_f_stps_res.c	\
	for_algoritm_find.c			\
	for_algoritm_order.c		\
	for_algoritm_preparing.c	\
	for_algoritm_step_res.c		\
	for_algoritm_steps_al.c		\
	for_algoritm_steps_ar.c		\
	free_list_chains.c			\
	ft_longatoi.c				\
	len_size_of_lists.c			\
	lists.c						\
	main_push_swap.c			\
	other_algoritms.c			\
	other_algoritms_sorting.c	\
	parser.c					\
	parser_checkers.c			\
	parser_helpers.c			\
	quicksort.c					\
	run_operators.c				\
	first_args_checker.c		\

CHECKER_SRC_NAME = 				\
	check_order.c				\
	free_list_chains.c			\
	ft_longatoi.c				\
	len_size_of_lists.c			\
	lists.c						\
	parser.c					\
	parser_checkers.c			\
	parser_helpers.c			\
	run_operators.c				\
	main_checker.c				\
	action_ch_part_four.c		\
	action_ch_part_one.c		\
	action_ch_part_three.c		\
	action_ch_part_two.c		\
	checker.c					\
	first_args_checker.c		\

FLAGS = 	-Wall -Werror -Wextra

PUSH_SWAP_OBJ_NAME = $(PUSH_SWAP_SRC_NAME:.c=.o)
CHECKER_OBJ_NAME = $(CHECKER_SRC_NAME:.c=.o)

all: $(PUSH_SWAP_NAME) $(CHECKER_NAME)

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ) $(INCLUDES_FILES)
	@make lib_refresh
	@mkdir -p $(PUSH_SWAP_OBJ_DIR)
	gcc $(FLAGS) -o $(PUSH_SWAP_NAME) $(PUSH_SWAP_OBJ) -lft -L $(LIBFT_DIR)

$(PUSH_SWAP_OBJ_DIR)%.o: $(SRC)%.c $(INCLUDES_FILES)
	@mkdir -p $(PUSH_SWAP_OBJ_DIR)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -o $@ -c $<

$(CHECKER_NAME): $(CHECKER_OBJ) $(INCLUDES_FILES)
	@make lib_refresh
	@mkdir -p $(CHECKER_OBJ_DIR)
	gcc $(FLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJ) -lft -L $(LIBFT_DIR)

$(CHECKER_OBJ_DIR)%.o: $(SRC)%.c $(INCLUDES_FILES)
	@mkdir -p $(CHECKER_OBJ_DIR)
	gcc $(FLAGS) -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -o $@ -c $<
	
lib_refresh:
	@make -C $(LIBFT_DIR)

clean:
	@find . -name ".DS_Store" -delete
	rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(PUSH_SWAP_NAME)
	rm -f $(CHECKER_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
