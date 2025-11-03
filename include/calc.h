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
	char		*value;
}	t_lexer;

#endif
