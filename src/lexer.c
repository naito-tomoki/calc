#include "calc.h"
#include "lexer.h"
#include "utils.h"
#include <stdbool.h>
#include <stdlib.h>

static int
is_lexer_ifs(int c)
{
	return isspace_s(c);
}

static size_t
lexer_ifs_len(const char f[static 1])
{
	const char *cp = f;
	while (is_lexer_ifs(*f)) f++;
	return (f - cp);
}

static int
lexer_search_token(const char f[static 1], int inf, const t_token_info info[inf])
{
	for (int i = 0; i < inf; i++)
	{
		const char *t = info[i].token;
		if (!strncmp_s(f, t, strlen_s(t))) return i;
	}
	return -1;
}

static size_t
lexer_token_len(const char f[static 1], int inf, const t_token_info info[inf], int hit)
{
	if (hit != -1) return strlen_s(info[hit].token);
	const char *cp = f;
	while (*f)
	{
		if (is_lexer_ifs(*f)) break ;
		if (lexer_search_token(f, inf, info) != -1) break ;
		f++;
	}
	return (f - cp);
}

static char *
lexer_dup_token(const char f[static 1], int inf, const t_token_info info[inf], int hit)
{
	if (hit != -1) return strdup_s(info[hit].token);
	return strndup_s(f, lexer_token_len(f, inf, info, hit) + sizeof(char));
}

static t_lexer *
lexer_last_elem(t_lexer *lexer)
{
	if (!lexer) return lexer;
	while (lexer->next) lexer = lexer->next;
	return lexer;
}

static int
lexer_add_elem(const char f[static 1], t_lexer *lexer[static 1], t_token_type def_type,
		int inf, const t_token_info info[inf], int hit)
{
	t_lexer *r = malloc(sizeof(t_lexer));
	if (!r) return false;
	if (!(r->value = lexer_dup_token(f, inf, info, hit))) return (free(r), false);
	r->type = (hit != -1 ? info[hit].type: def_type);
	r->next = NULL;
	if (*lexer)
		lexer_last_elem(*lexer)->next = r;
	else
		*lexer = r;
	return true;
}

static int
lexer_set(const char calc_form[static 1], t_lexer *lexer[static 1])
{
	const t_token_type def_type = TOKEN_NUM;
	const t_token_info info[] = {
		{token: "+", type: TOKEN_PLUS},
		{token: "-", type: TOKEN_MINUS},
	};
	const int inf = (sizeof(info) / sizeof(info[0]));
	while (*calc_form)
	{
		calc_form += lexer_ifs_len(calc_form);
		int hit = lexer_search_token(calc_form, inf, info);
		if (!lexer_add_elem(calc_form, lexer, def_type, inf, info, hit))
			return (lexer_free(lexer), false);
		calc_form += lexer_token_len(calc_form, inf, info, hit);
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

void
lexer_free(t_lexer **lexer)
{
	if (!lexer) return ;
	t_lexer *cp = *lexer;
	t_lexer *n;
	while (cp)
	{
		n = cp->next;
		free(cp->value);
		free(cp);
		cp = n;
	}
	*lexer = NULL;
}