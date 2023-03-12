# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okraus <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 15:40:17 by okraus            #+#    #+#              #
#    Updated: 2023/03/12 17:30:32 by okraus           ###   ########.fr        #
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
#NAME_B		=	checker
INCS_F		=	libft/
INCS		=	libft.a
CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3
OBJ_DIR		=	objects/
#NUM_COM		:=	make -n | wc -l

# SOURCES

SRC			=	$(addprefix $(SRC_PS_DIR), $(addsuffix .c, $(SRC_PS))) \
				$(addprefix $(SRC_CH_DIR), $(addsuffix .c, $(SRC_CH)))

# Source directories

SRC_PS_DIR	=	src_ps/
SRC_CH_DIR	=	src_ch/

# Push swap functions

SRC_PS		=	ft_bruteforce \
				ft_five_generator \
				ft_index_array \
				ft_initialize_stack_a \
				ft_stack_manipulation \
				push_swap \
				temp.c

# Checker functions

SRC_CH		=	

# Formating

NRM_FORMAT	=	\033[0m

GREEN		=	\033[1;32m
YELLOW		=	\033[1;93m
RED			=	\033[1;31m
REVERSE		=	\033[7m
RETURN		=	\033[1F\r\033[2K

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

OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_PS))) \
				$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_CG))) 

# RULES

all:			announce $(LIBFT) $(NAME)

#				@$(PRINT2)
#				@$(PRINT1)
#				@$(ECHO) All done
#				@echo "$(GREEN)Amazing <<$(REVERSE)libft.a$(NRM_FORMAT)$(GREEN)>> compiled!$(NRM_FORMAT)"
				

# MESSAGES 

announce: 
				@echo "$(RED)Not compiling because library already exists\n$(NRM_FORMAT)"


# COMPILATION

$(OBJ_DIR)%.o:	$(SRC_PS_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@sleep 0.01
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling Libft: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(OBJ_DIR)%.o:	$(SRC_CH_DIR)%.c
				@mkdir -p $(OBJ_DIR)
				@sleep 0.01
				@echo "$(RETURN)$(RETURN)$(YELLOW)Compiling extras: $< $(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(CC) $(CFLAGS) -c $< -o $@
				@$(ECHO)

$(NAME): 		$(OBJ) # pf_msg
				@echo "$(RETURN)$(RETURN)$(GREEN)Compilation complete!$(NRM_FORMAT)"
				@$(LIBC) $(NAME) $(OBJ)
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)
				@echo "$(GREEN)Amazing <<$(REVERSE)libft.a$(NRM_FORMAT)$(GREEN)>> compiled!$(NRM_FORMAT)"

$(LIBFT):
				@make -C $(LIBFT_F)
				@cp libft/libft.a .
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)

# Fclean library

clean:
				@make fclean -C $(LIBFT_F)
				@echo "$(RED)Objects removed!$(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)

# Remove the program after running clean

fclean:			clean
				@rm $(NAME)
				@rm $(NAME_B)
				@rm $(LIBFT)
				@echo "$(RETURN)$(RED)Library deleted!$(NRM_FORMAT)"
				@$(PRINT2)
				@$(PRINT1)
				@$(ECHO)

# Remove stuff and make it all again

re: fclean all
	@$(PRINT2)
	@$(PRINT1)
	@$(ECHO)

# Phony stuff for rules

.PHONY: all announce clean compiling_msg fclean re pf_msg gnl_msg lib_msg start_msg
