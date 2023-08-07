/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:51:09 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/07 10:49:53 by mreidenb         ###   ########.fr       */
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

/// @brief Checks how many potential tokens there are in a string.
/// Used to calculate allocation size for token array.
/// @param s String to count number of tokens in.
/// @return Returns number of tokens in input.
/// Returns negative number if unclosed quotes.
int		tokencount(const char *s);

//Lexer

/// @brief Gets the next token in the input.
/// Call with Input = NULL to reset after complete command call.
/// @param command Input String.
/// @return Returns the next available token of the input.
t_Token	get_next_token(char *command);

/// @brief Gets the String inside the quotes, returns it and moves the index.
/// @param command Command with quotes.
/// @param i Pointer to current index of the lexer.
/// @return Returns the String inside the quotes.
char	*quote(char *command, int *i);

/// @brief Checks if given character Needs to be quotet or not.
/// @param c Charachter to be ckecked
/// @return Returns 2 if given Charachter needs to be quoted but no whitespace.
/// Returns 1 if Charachter is whitespace. Returns 0 if Charachter is normal.
int		is_unquotable(char c);

/// @brief Checks if $ is just a single $ or a indicator for a variable.
/// Throws Error Message when unexpected token is encountered
/// @param input Input where $ was encountered
/// @param i Pointer to current index of \p input
/// @return Returns $ as a word token if it's just a $ space with whitespaces.
/// Returns the word as \a token.lexme after the $ as a variable token.
/// Returns Err token and prints error msg if unexpected token is encountered.
t_Token	lex_dollar(char *input, int *i);

//Parser
int		parser(t_Token *tokens);

/// @brief Checks if the token is valid for redirect meaning
/// Word, Variable, String, Name of a command
/// @param token Token to be checked
/// @return Returns 1 if token is allowed. 0 if not
int		is_allowed_token(t_Token token);

//Error

/// @brief Just frees the input
/// @param input Input to be freed
/// @return Returns 0
int		empty_input(char *input);

/// @brief prints a quote error to STDIN, adding input to history
/// freeing input
/// @param input Input to add to history and free
/// @return Returns -1
int		bad_quote(char *input);

/// @brief Prints parser error message and the token wich caused it
/// @param err_token The unexpected token
/// @return Returns -3
int		unexpected_token(t_Token err_token);

#endif
