#include <unistd.h>
#include "calc.h"
#include "lexer.h"
#include "parser.h"
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
#else
	(void)token;
#endif
}

#if defined(DEBUG)
static void
print_ast_deep(t_parser *ast, int deep)
{
	if (!ast) return ;
	for (int i = 0; i < deep; i++) printf(" ");
	printf("type: %d", ast->type);
	if (ast->type == TOKEN_NUM) printf(" value: %d\n", ast->value);
	printf("\n");
	print_ast_deep(ast->left, deep + 1);
	print_ast_deep(ast->right, deep + 1);
}
#endif

void
print_ast(t_parser *ast)
{
#if defined(DEBUG)
	print_ast_deep(ast, 0);
#else
	(void)ast;
#endif
}

int
main(int argc, char **argv)
{
	char *calc_form = conn_strs(argc - 1, argv + 1, " ");
	t_lexer *token;
	if (!lexer(calc_form, &token)) return 1;
	print_lexer(token);
	t_parser *ast;
	parser(token, &ast);
	print_ast(ast);
	lexer_free(&token);
	free(calc_form);
	return 0;
}
