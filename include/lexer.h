#ifndef LEXER_H
# define LEXER_H

# include "calc.h"

typedef struct s_token_info
{
	const char	*token;
	t_token_type	type;
}	t_token_info;

int
lexer(const char *calc_form, t_lexer **lexer);

void
lexer_free(t_lexer **lexer);

#endif
