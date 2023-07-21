/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:51:09 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/21 18:55:43 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include "../lib/42-libft/libft.h"
# include <stdbool.h>

typedef enum TokenType
{
	TOKEN_WORD,
	TOKEN_VARIABLE,
	TOKEN_COMMAND_NAME,
	TOKEN_DOLLAR,
	TOKEN_LITERAL_CHARS,
	TOKEN_LITERAL_STRING,
	TOKEN_REDIRECT,
	TOKEN_GREAT,
	TOKEN_LESS,
	TOKEN_GREAT_GREAT,
	TOKEN_LESS_LESS,
	TOKEN_PIPE,
	TOKEN_LEFT_PAREN,
	TOKEN_RIGHT_PAREN,
	TOKEN_END
}	t_TokenType;

typedef struct Token
{
	t_TokenType	type;
	char		*lexeme;
}	t_Token;

typedef struct SimpleCommand
{
	int		arg_count;
	char	type;
	char	**arguments;
	bool	option;
}	t_SimpleCommand;


typedef struct Command
{

	char	*in_file;
	char	*out_file;
}	t_Command;


t_Token	get_next_token(char *command);
char	*quote(char *command, int *i);
int		is_unquotable(char c);

#endif
