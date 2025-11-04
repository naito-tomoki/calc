#include <unistd.h>
#include "calc.h"
#include "lexer.h"
#include "utils.h"
#include <stdlib.h>

int
main(int argc, char **argv)
{
	char *calc_form = conn_strs(argc - 1, argv + 1, " ");
	t_lexer *token;
	if (!lexer(calc_form, &token)) return 1;
	lexer_free(&token);
	free(calc_form);
	return 0;
}
