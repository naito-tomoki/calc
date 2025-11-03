#include <unistd.h>
#include "utils.h"

int
main(int argc, char **argv)
{
	const char *calc_form = conn_strs(argc - 1, argv + 1);
#include <stdio.h>
if (calc_form)
puts(calc_form);
	return 0;
}
