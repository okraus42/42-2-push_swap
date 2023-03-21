# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 15:40:17 by okraus            #+#    #+#              #
#    Updated: 2023/03/21 15:19:02 by okraus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef ECHO
HIT_TOTAL	!=	${MAKE} ${MAKECMDGOALS} --dry-run ECHO="HIT_MARK" | grep -c "HIT_MARK"
HIT_COUNT1	=	$(eval HIT_N != expr ${HIT_N} + 1)${HIT_N}
HIT_COUNT2	=	$(eval HIT_M != expr ${HIT_M} + 1)${HIT_M}
HIT_COUNT3	=	$(eval HIT_O != expr ${HIT_O} + $(BAR_LENGTH))${HIT_O}
PERC		=	$(shell expr $(HIT_COUNT3) / $(HIT_TOTAL) | bc)
ECHO		=	echo "[`expr ${HIT_COUNT1} '*' 100 / ${HIT_TOTAL}`%]"
endif

NAME		=	push_swap
NAME_B		=	checker
LIBFT_F		=	libft/
LIBFT		=	libft.a
CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3
OBJ_DIR		=	objects/
SLEEP		=	#sleep 0.5

# SOURCES

SRC			=	$(addprefix $(SRC_PS_DIR), $(addsuffix .c, $(SRC_PS)))
SRC_B		=	$(addprefix $(SRC_CH_DIR), $(addsuffix .c, $(SRC_CH)))

# Source directories

SRC_PS_DIR	=	src_ps/
SRC_CH_DIR	=	src_ch/

# Push swap functions

SRC_PS		=	ft_bruteforce \
				ft_bruteforce2 \
				ft_pusha \
				ft_pusha_prefill \
				ft_pusha_smart \
				ft_pusha_utils \
				ft_pushb \
				ft_errors \
				ft_five_generator \
				ft_index_array \
				ft_initialize_stack_a \
				ft_ps_sortcheck \
				ft_stack_manipulation_ps \
				ft_stack_manipulation_rx \
				ft_stack_manipulation_rrx \
				push_swap

# Checker functions

SRC_CH		=	checker \
				ft_ch_gnl \
				ft_errors \
				ft_index_array \
				ft_initialize_stack_a \
				ft_ps_sortcheck \
				ft_stack_manipulation_ps \
				ft_stack_manipulation_rx \
				ft_stack_manipulation_rrx

# Formating

NRM_FORMAT	=	\033[0m

GREEN		=	\033[1;32m
YELLOW		=	\033[1;93m
RED			=	\033[1;31m
REVERSE		=	\033[7m
RETURN		=	#\033[1F\r\033[2K

# Printing

BAR_LENGTH	:=	50
PRINT1		=	printf "[$(HIT_COUNT2)/$(HIT_TOTAL)]" ;
PRINT2		=	for num in `seq 1 $(BAR_LENGTH)` ; do \
					if [ $$num -le $(PERC) ] ; then \
						printf "$(REVERSE) $(NRM_FORMAT)" ; \
					else \
						printf " " ; \
        			fi \
    			done

# Objects

OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_PS)))

OBJ_B		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_CH))) 

# RULES

all:			announce $(LIBFT) $(NAME)
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)
				@echo "$(GREEN)Amazing <<$(REVERSE)push_swap$(NRM_FORMAT)$(GREEN)>> compiled!$(NRM_FORMAT)"
				

bonus:			$(LIBFT) $(NAME_B)
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)
				@echo "$(GREEN)Amazing <<$(REVERSE)checker$(NRM_FORMAT)$(GREEN)>> compiled!$(NRM_FORMAT)"

# MESSAGES 

announce: 
				@echo "$(RED)You should not see this (unless the program already exists)\n$(NRM_FORMAT)"


# COMPILATION

$(OBJ_DIR)%.o:	$(SRC_PS_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling PUSH_SWAP: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(OBJ_DIR)%.o:	$(SRC_CH_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@$(SLEEP)
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling CHCKER: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(NAME): 		$(OBJ)
				@echo "$(RETURN)$(RETURN)$(GREEN)Libft compilation complete!$(NRM_FORMAT)"
				@$(CC) $(CFLAGS) $(SRC) libft.a -o $(NAME)
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)
				@echo "$(RETURN)$(RETURN)$(GREEN)Push swap compiled!$(NRM_FORMAT)"

$(NAME_B): 		$(OBJ_B)
				@echo "$(RETURN)$(RETURN)$(GREEN)Libft compilation complete!$(NRM_FORMAT)"
				@$(CC) $(CFLAGS) $(SRC_B) libft.a -o $(NAME_B)
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)
				@echo "$(RETURN)$(RETURN)$(GREEN)Checker compiled!$(NRM_FORMAT)"

$(LIBFT):
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling LIBFT: $< $(NRM_FORMAT)"
				@make -s -C $(LIBFT_F)
				@cp libft/libft.a .
				@echo "$(YELLOW)Compiling PUSH SWAP: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)

# Fclean library

clean:
				@rm -rf $(OBJ_DIR)
				@make fclean -s -C $(LIBFT_F)
				@echo "$(RED)Objects removed!$(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)

# Remove the program after running clean

fclean:			clean
				@rm $(LIBFT)
				@rm $(NAME)
				@rm $(NAME_B)
				@echo "$(RETURN)$(RED)Library and program deleted!$(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)

# Remove stuff and make it all again

re: 			fclean all
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)

# Phony stuff for rules

.PHONY: all announce clean fclean re bonus
