# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkollner <jkollner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/08 19:53:44 by jonahkollne       #+#    #+#              #
#    Updated: 2023/08/28 16:34:34 by jkollner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM	= rm -f

################################################################################
###########################-Files.c by Folder-##################################
################################################################################

SRC				= $(addprefix $(SRC_DIR),$(addsuffix .c, $(SRC_FILES)))
SRC_DIR			= src/
SRC_FILES		= minishell

UTILS			= $(addprefix $(UTILS_DIR),$(addsuffix .c, $(UTILS_FILES)))
UTILS_DIR		= $(addprefix $(SRC_DIR), utils/)
UTILS_FILES		= visual_prompt signal_handler directory_handler executer functions

PARSER			= $(addprefix $(PARSER_DIR),$(addsuffix .c, $(PARSER_FILES)))
PARSER_DIR		= $(addprefix $(SRC_DIR), parser/)
PARSER_FILES	= input lexer parser

PARSER_UTIL		= $(addprefix $(PARSER_UTIL_DIR),$(addsuffix .c, $(PARSER_UTIL_FIL)))
PARSER_UTIL_DIR	= $(addprefix $(SRC_DIR), parser/utils/)
PARSER_UTIL_FIL	= lexer_error parser_error parser_utils quotes expander heredoc

##################################-HEADER-######################################

HEADER			= $(addprefix $(HEADER_DIR), $(HEADER_DIR))
HEADER_DIR		= include/
HEADER_FILES	= minishell.h

ALL_C			= $(SRC) $(UTILS) $(PARSER) $(PARSER_UTIL)

################################################################################
##################################-Objects-#####################################
################################################################################

OBJ_DIR			=	obj/
ALL_OBJ			=	$(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(ALL_C))
ALL_OBJ_DIR		=	$(sort $(dir $(ALL_OBJ)))


all: libft $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR) $(LIBFT_INCLUDE)

$(NAME):$(ALL_OBJ_DIR) $(ALL_OBJ)
	$(CC) $(ALL_OBJ) -o $(NAME) $(LIBFT) -lreadline

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)

fclean:	clean
	${RM} ${NAME}

re:		fclean all

$(ALL_OBJ_DIR):
	@mkdir -p $(ALL_OBJ_DIR)

LIBFT			=	$(LIBFT_DIR)$(LIBFT_LIB)
LIBFT_LIB		=	libft.a
LIBFT_DIR		=	lib/42-libft/
LIBFT_INCLUDE	=	-I ./lib/42-libft

$(LIBFT):
	@git submodule init $(REDIRECT)
	@git submodule update $(REDIRECT)
	@make allclean -C lib/42-libft

libft: $(LIBFT)

.PHONY:	all clean fclean re prinf

################################################
