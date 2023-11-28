# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albrusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:06:40 by albrusso          #+#    #+#              #
#    Updated: 2023/11/21 14:23:50 by albrusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME = philo
SRC = src/main.c src/init.c src/routine.c src/supervisor.c src/thread.c src/utils.c
OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -pthread -g

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n🎉${GREEN}> Compilation of is success 🎉"
clean:
	@rm -f $(OBJ)
	@echo "${YELLOW}> All objects files of have been deleted 🧹"
fclean: clean
	@rm -f $(NAME)
	@echo "${YELLOW}> Cleaning of has been done 🧹"
re: fclean all
.PHONY: all clean fclean