#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define ERROR -1
#define END 0

char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(const char *s, unsigned int start, size_t len);
int findchr(const char *str);
size_t  ft_strlen(const char *str);
char    *get_next_line(int fd);

#endif
