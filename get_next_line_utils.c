#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
        size_t  len;

        len = 0;
        while(str[len])
                len++;
        return len;
}

int findchr(const char *str)
{
        size_t  len;

        len = 0;
        if(!str)
                return -1;
        while(str[len])
        {
                if(str[len] == '\n')
                        return len;
        len++;
        }
        return -1;
}

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
        char    *ret;
        size_t  s_len;

        if (!s)
                return (0);
        s_len = ft_strlen(s);
        if (start >= s_len)
                return (strdup(""));
        if (s_len - start < len)
                len = s_len - start;
        ret = malloc(sizeof(char) * (len + 1));
        if (!ret)
                return (0);
        strlcpy(ret, s + start, len + 1);
        return (ret);
}

//special strjoin
//s1 == stash
char    *ft_strjoin(char const *s1, char const *s2)
{
        size_t  len1;
        size_t  len2;
        char    *str;

        if (!s1 || !s2)
                return (NULL);
        len1 = ft_strlen(s1);
        len2 = ft_strlen(s2);
        str = malloc(sizeof(char) * (len1 + len2 + 1));
        if (!str)
        {
                free((char *)s1);
                return (NULL);
        }
        strlcpy(str, s1, len1 + 1);
        strlcat(str + len1, s2, len2 + 1);
        free((char *)s1);
        return (str);
}
