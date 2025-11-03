#include "calc.h"
#include <stdbool.h>

static int
lexer_set(const char calc_form[static 1], t_lexer *lexer[static 1])
{

}

int
lexer(const char *calc_form, t_lexer **lexer)
{
	if (!calc_form) return false;
	if (!lexer) return false;

	return lexer_set(calc_form, lexer);
}
