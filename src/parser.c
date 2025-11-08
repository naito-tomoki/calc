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
	if (!token) return false;
	t_parser *left = NULL;
	if (!parse_factor(token, &left))
		return false;

	token = token->next;
	if (!token)
	{
		*ast = left;
		return true;
	}
	if (token->type != TOKEN_PLUS && token->type != TOKEN_MINUS)
	{
		*ast = left;
		return true;
	}

	t_parser *node = malloc(sizeof(t_parser));
	if (!node)
	{
		free(left);
		return false;
	}

	if (!parse_expr(token->next, &node->right))
	{
		free(left);
		free(node);
		return false;
	}
	node->left = left;
	(*ast) = node;
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
