/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:51:09 by mreidenb          #+#    #+#             */
/*   Updated: 2023/08/17 10:43:41 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include "../../lib/42-libft/libft.h"
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

typedef struct Command
{
	t_Token	type;
	int		arg_i;
	int		arg_count;
	t_Token	*arguments;
	char	*in_file;
	char	*out_file;
}	t_Command;

//Input

/// @brief 
/// @param input 
/// @param env 
/// @return 
int			input_to_lex(char *input, char **env);

/// @brief Checks how many potential tokens there are in a string.
/// Used to calculate allocation size for token array.
/// @param s String to count number of tokens in.
/// @return Returns number of tokens in input.
/// Returns negative number if unclosed quotes.
int			tokencount(const char *s);

//Lexer

/// @brief Gets the next token in the input.
/// Call with Input = NULL to reset after complete command call.
/// @param command Input String.
/// @return Returns the next available token of the input.
t_Token		get_next_token(char *input, t_Token token);

/// @brief Gets the String inside the quotes, returns it and moves the index.
/// @param command Command with quotes.
/// @param i Pointer to current index of the lexer.
/// @return Returns the String inside the quotes.
char		*quote(char *command, int *i);

/// @brief Checks if given character Needs to be quotet or not.
/// @param c Charachter to be ckecked.
/// @return Returns 2 if given Charachter needs to be quoted but no whitespace.
/// Returns 1 if Charachter is whitespace. Returns 0 if Charachter is normal.
int			is_unquotable(char c);

/// @brief Checks if '$' at \p i is just a single '$' or a indicator for a
/// variable. Throws Error Message when unexpected token is encountered.
/// @param input Input where '$' was encountered.
/// @param i Pointer to the '$' index in \p input
/// @return Returns '$' as a word token if the '$' is just a lonely '$'.
/// Returns the word after the '$' in \a token.lexme  as a variable token.
/// Returns Err token and prints error msg if unexpected token is encountered.
t_Token		lex_dollar(char *input, int *i);

//Parser
int			parser(t_Token *tokens);

/// @brief Checks if the token is valid for redirect meaning
/// Word, Variable, String, Name of a command
/// @param token Token to be checked
/// @return Returns 1 if token is allowed. 0 if not
int			is_allowed_token(t_Token token);

/// @brief Counts and returns number of Commands.
/// @param tokens Tokens with Commands inside.
/// @return Returns n number of Command, n >= 1.
int			cmd_count(t_Token *tokens);

/// @brief Counts number of arguments until End or Pipe is encountered.
/// @param tokens Pointer to where to start counting.
/// @return Returns number of arguments. Return -1 if Error.
int			cmd_arg_count(t_Token *tokens);

void		free_unused_tokens(t_Token *tokens);

t_Command	std_command(t_Command command, t_Token *tokens);

//Error

/// @brief Just frees the input
/// @param input Input to be freed
/// @return Returns 0
int			empty_input(char *input);

/// @brief prints a quote error to STDIN, adding input to history and
/// freeing input.
/// @param input Input to add to history and free
/// @return Returns -1
int			bad_quote(char *input);

/// @brief Prints parser error message and the token wich caused it
/// @param err_token The unexpected token
/// @return Returns -3
int			unexpected_token(t_Token err_token);

int			unclosed_pipe(void);

#endif
