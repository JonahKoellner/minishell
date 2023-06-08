# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 19:53:44 by jonahkollne       #+#    #+#              #
#    Updated: 2023/06/08 20:52:29 by jonahkollne      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=========== Compiler ==============#
CC = cc
FLAGS = -Wall -Werror -Wextra -arch arm64

#=========== Name ==============#
NAME = lib/minishell.exe

#=========== Files ==============#
CFILES = src/minishell.c
OBJDIR = bin/
COBJ = $(patsubst src/%.c, bin/%.o, $(CFILES))

all: $(NAME)

$(NAME): $(COBJ)
	$(CC) $(FLAGS) $(COBJ) -o $@

$(COBJ): $(CFILES)
	$(CC) $(CFLAGS) $< -c -o $@
clean:
	rm -vf $(COBJ)

fclean:	clean
	rm -vf $(NAME)

re:	fclean	all

.PHONY: all clean fclean re
