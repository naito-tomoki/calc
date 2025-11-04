#ifndef UTILS_H
# define UTILS_H

# include <aio.h>

int
isspace_s(int c);

size_t
strlen_s(const char *s);

char *
strcpy_s(char *dst, const char *src);

char *
strncpy_s(char *dst, const char *src, size_t n);

char *
strcat_s(char *dst, const char *src);

int
strncmp_s(const char *s1, const char *s2, size_t n);

char *
strdup_s(const char *s);

char *
strndup_s(const char *s, size_t n);

size_t
len_strs(int elems, char **strs);

char *
conn_strs(int elems, char **strs, const char *pad);

#endif
