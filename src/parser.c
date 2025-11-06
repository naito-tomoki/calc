#include "calc.h"
#include <stdbool.h>
#include <stdlib.h>

int
parser(t_lexer *token, t_parser **parse)
{
	if (!token) return false;
	if (!parse) return false;
	*parse = NULL;
	return parser_set(token, parse);
}
