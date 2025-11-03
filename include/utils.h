#ifndef UTILS_H
# define UTILS_H

# include <aio.h>

size_t
strlen_s(const char *s);

char *
strcpy_s(char *dst, const char *src);

char *
strcat_s(char *dst, const char *src);

size_t
len_strs(int elems, char **strs);

char *
conn_strs(int elems, char **strs, const char *pad);

#endif
