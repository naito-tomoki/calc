#include "calc.h"
#include "lexer.h"
#include "utils.h"
#include <stdbool.h>

static int
lexer_search_token(const char calc_form[static 1], int inf, const t_token_info info[inf])
{
	for (int i = 0; i < inf; i++)
	{
		const char *t = info[i].token;
		if (!strncmp_s(calc_form, t, strlen_s(t))) return i;
	}
	return -1;
}


static int
lexer_set(const char calc_form[static 1], t_lexer *lexer[static 1])
{
	const t_token_info info[] = {
		{token: "+", type: TOKEN_PLUS},
		{token: "-", type: TOKEN_PLUS},
	};
	while (*calc_form)
	{
#include <stdio.h>
printf("t: %d\n", lexer_search_token(calc_form, sizeof(info) / sizeof(info[0]), info));
		calc_form++;
	}
	return true;
}

int
lexer(const char *calc_form, t_lexer **lexer)
{
	if (!calc_form) return false;
	if (!lexer) return false;
	*lexer = NULL;
	return lexer_set(calc_form, lexer);
}
