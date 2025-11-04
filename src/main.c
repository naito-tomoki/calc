#include <unistd.h>
#include "calc.h"
#include "lexer.h"
#include "utils.h"

int
main(int argc, char **argv)
{
	const char *calc_form =
		conn_strs(argc - 1, argv + 1, " ");
	t_lexer *token;
	if (!lexer(calc_form, &token)) return 1;
	return 0;
}
