#include <unistd.h>
#include "calc.h"
#include "lexer.h"
#include "utils.h"
#include <stdlib.h>

void
print_lexer(t_lexer *token)
{
#if defined(DEBUG)
# include <stdio.h>
	if (!token) return ;
	printf("value: %s, type: %d\n", token->value, token->type);
	print_lexer(token->next);
#endif
}

int
main(int argc, char **argv)
{
	char *calc_form = conn_strs(argc - 1, argv + 1, " ");
	t_lexer *token;
	if (!lexer(calc_form, &token)) return 1;
	print_lexer(token);
	lexer_free(&token);
	free(calc_form);
	return 0;
}
