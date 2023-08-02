/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:51:09 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/01 18:09:47 by mreidenb         ###   ########.fr       */
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
	TOKEN_END,
	ERR
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
	t_SimpleCommand	*commands;
	char			*in_file;
	char			*out_file;
}	t_Command;

//Input
int		tokencount(const char *s);

//Lexer
//gets the next token, after complete command call with input = NULL to reset
t_Token	get_next_token(char *command);
char	*quote(char *command, int *i);
int		is_unquotable(char c);
t_Token	lex_dollar(char *input, int *i);

//Parser
int		parser(t_Token *tokens);
int		is_allowed_token(t_Token token);

//Error
int		bad_quote(char *input);
int		empty_input(char *input);
int		unexpected_token(t_Token err_token);

#endif
