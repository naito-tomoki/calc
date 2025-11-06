#include "calc.h"
#include <stdbool.h>
#include <stdlib.h>

static int
parse_expr(t_lexer *token, t_parser **ast)
{
	return true;
}

static int
parse_term(t_lexer *token, t_parser **ast)
{
	return true;
}

static int
parse_factor(t_lexer *token, t_parser **ast)
{
	return true;
}

int
parser(t_lexer *token, t_parser **ast)
{
	if (!token) return false;
	if (!parse) return false;
	*ast = NULL;
	parse_factor(token, ast);
	return (ast != NULL);
}
