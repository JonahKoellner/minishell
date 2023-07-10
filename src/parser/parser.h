/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mreidenb <mreidenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:51:09 by mreidenb          #+#    #+#             */
/*   Updated: 2023/07/08 16:44:24 by mreidenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include "../lib/42-libft/libft.h"

typedef enum TokenType
{
	TOKEN_WORD,
	TOKEN_VARIABLE,
	TOKEN_COMMAND_NAME,
	TOKEN_REDIRECT,
	TOKEN_GREAT,
	TOKEN_LESS,
	TOKEN_GREAT_GREAT,
	TOKEN_LESS_LESS,
	TOKEN_PIPE,
	TOKEN_LEFT_PAREN,
	TOKEN_RIGHT_PAREN
}	t_TokenType;

typedef struct Token
{
	t_TokenType	type;
	char		*lexeme;
}	t_Token;

t_Token	get_next_token(char *command);

#endif
