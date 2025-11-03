#include "utils.h"
#include <stdlib.h>

size_t
strlen_s(const char *s)
{
	if (!s) return 0;
	const char *cp = s;
	while (*s) s++;
	return (s - cp);
}

size_t
len_strs(int elems, char **strs)
{
	if (elems < 1) return 0;
	if (!strs) return 0;
	size_t sum = 0;
	for (int i = 0; i < elems; i++)
		sum += strlen_s(strs[i]);
	return sum;
}

//char *
//conn_strs(int elems, char **strs)
//{
//	if (elems < 1) return NULL;
//	if (!strs) return NULL;
//	char *res = malloc();
//	return res;
//}
