#ifndef CALC_H
# define CALC_H

typedef enum
{
	TOKEN_NUM,
	TOKEN_PLUS,
	TOKEN_MINUS
}	t_token_type;

typedef struct s_lexer
{
	t_token_type	type;
	char			*value;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_parser
{
	t_token_type	type;
	int				value;
	struct s_parser	*left;
	struct s_parser *right;
}	t_parser;

#endif
