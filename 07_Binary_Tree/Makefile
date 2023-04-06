# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkim3 <minkim3@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 16:56:08 by minkim3           #+#    #+#              #
#    Updated: 2023/04/06 16:20:34 by minkim3          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -MMD -fsanitize=address
NAME            = binary_tree
RM              = rm -f

EXEC            = binary_tree
SRCS_PATH       = ./srcs/
SRCS      	    = main.c\
				  binary_tree.c\
				  linked_queue.c\
				  linked_stack.c
SOURCES         = $(addprefix $(SRCS_PATH), $(SRCS))
OBJECTS         = $(SOURCES:.c=.o)

HEADER_PATH     = ./includes/
S_HEADER        = binary_tree.h
HEADER          = $(addprefix $(HEADER_PATH), $(S_HEADER))

RED             = \033[1;31m
PINK            = \033[1;35m
GREEN           = \033[1;32m
YELLOW          = \033[1;33m
BLUE            = \033[1;34m
DEFAULT         = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)
	@echo -e "$(GREEN)create $(EXEC)!$(DEFAULT)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJECTS)
	@$(RM) $(OBJECTS:.o=.d)
	@echo -e "$(BLUE)delete object files!$(DEFAULT)"

fclean: clean
	@$(RM) $(EXEC)
	@echo -e "$(PINK)delete all!$(DEFAULT)"

re:
	@make fclean
	@make all

norm:
	norminette -R CheckDefine

.PHONY: all clean fclean re norm

-include $(OBJECTS:.o=.d)
