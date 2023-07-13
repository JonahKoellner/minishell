# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonahkollner <jonahkollner@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 19:53:44 by jonahkollne       #+#    #+#              #
#    Updated: 2023/07/13 15:11:18 by jonahkollne      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##=========== Compiler ==============#
#CC = cc
#FLAGS = -Wall -Werror -Wextra -arch arm64

##=========== Name ==============#
#NAME = lib/minishell.exe

##=========== Files ==============#
#CFILES = src/minishell.c src/utils/visual_prompt.c
#OBJDIR = bin/
#COBJ = ${SRC:.c=.o}


#all: $(NAME)

#$(NAME): $(COBJ)
#	$(CC) $(FLAGS) $(COBJ) -o $@

#$(COBJ): $(CFILES)
#	$(CC) $(CFLAGS) $< -c -o $@
#clean:
#	rm -vf $(COBJ)

#fclean:	clean
#	rm -vf $(NAME)

#re:	fclean	all

#.PHONY: all clean fclean re




NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ../lib/42-libft/libft.a
SRC = utils/visual_prompt.c utils/signal_handler.c utils/directory_handler.c minishell.c
OBJ = ${SRC:.c=.o}
RM	= rm -f

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) -o $@ $(LIBFT)

src/%.o: src/%.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	@${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re prinf

################################################
