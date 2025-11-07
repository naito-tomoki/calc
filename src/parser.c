#include "calc.h"
#include <stdbool.h>
#include <stdlib.h>
#include "utils.h"

/* BNF
<number>	::=	(0|1|2|3|4|5|6|7|8|9)
<digits>	::=	<number> | <digits> <number>
<factor>	::= <digits>
<expr>		::= <factor>
				| <digits> + <factor>
				| <digits> - <factor>
*/

static int
parse_factor(t_lexer *token, t_parser **ast)
{
	*ast = NULL;
	if (!token) return true;
	t_parser *factor = malloc(sizeof(t_parser));
	if (!factor) return false;
	factor->left = NULL;
	factor->right = NULL;
	factor->type = token->type;
	factor->value = atoi_s(token->value);
	*ast = factor;
	return true;
}

static int
parse_expr(t_lexer *token, t_parser **ast)
{
	t_lexer *prev = NULL;
	while (token && token->type == TOKEN_NUM)
	{
		prev = token; token = token->next;
	}
	if (!token) return true;
	t_parser *expr = malloc(sizeof(t_parser));
	if (!expr) return false;
	expr->value = 0;
	expr->type = token->type;
	if (!parse_factor(prev, &expr->left))
	{
		free(expr);
		return true;
	}
	if (!parse_expr(token->next, &expr->right))
	{
		free(expr);
		return true;
	}
	*ast = expr;
	return true;
}

int
parser(t_lexer *token, t_parser **ast)
{
	if (!token) return false;
	if (!ast) return false;
	*ast = NULL;
	parse_expr(token, ast);
	return (ast != NULL);
}
