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

char *
strcpy_s(char *dst, const char *src)
{
	if (!dst) return NULL;
	if (!src) return dst;
	char *cp = dst;
	while (*src) *dst++ = *src++;
	*dst = 0;
	return cp;
}

char *
strcat_s(char *dst, const char *src)
{
	if (!dst) return NULL;
	char *cp = dst;
	strcpy_s(dst + strlen_s(dst), src);
	return cp;
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

char *
conn_strs(int elems, char **strs, const char *pad)
{
	if (elems < 1) return NULL;
	if (!strs) return NULL;
	char *res = malloc(len_strs(elems, strs) + sizeof(char)
			+ strlen_s(pad) * (elems - 1));
	if (!res) return NULL;
	*res = 0;
	while (elems--)
	{
		strcat_s(res, *strs++);
		if (elems) strcat_s(res, pad);
	}
	return res;
}
