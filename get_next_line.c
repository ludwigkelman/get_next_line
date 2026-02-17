#include "get_next_line.h"

char    *extract_line(char **stash, int status)
{
        int     pos;
        char    *line;
        char    *new_stash;
        int     stashlen;

        new_stash = NULL;
        if(!*stash || status == -1)
                return NULL;
        pos = findchr(*stash);
        if(pos >= 0)
                line = ft_substr(*stash, 0, pos + 1);
        else
                line = ft_substr(*stash, 0, ft_strlen(*stash));

        if(pos >= 0)
        {
                stashlen = strlen(*stash);
                if(pos + 1 != stashlen)
                        new_stash = ft_substr(*stash, pos + 1, stashlen - (pos + 1));
        }
        free(*stash);
        *stash = new_stash;
        return line;
}

int     read_line(int fd, char **stash)
{
        char    *mem;
        int bytes;

        while(findchr(*stash) == -1)
        {
                mem = malloc(sizeof(char) * (BUFFER_SIZE + 1));
                if(!mem)
                        return -1;
                bytes = read(fd, mem, BUFFER_SIZE);
                if(bytes == ERROR || bytes == END)
                {
                        free(mem);
                        if(bytes == END)
                                return 0;
                        free(*stash);
                        *stash = NULL;
                        return -1;
                }
                else
                {
                        mem[bytes] = 0;
                        if(!*stash)
                                *stash = strdup(mem);
                        else
                                *stash = ft_strjoin(*stash, mem);
                        free(mem);
                }
        }
        return bytes;
}

char    *get_next_line(int fd)
{
        static char *stash;
        char    *line;
        int     status;

        status = 1;
        if(findchr(stash) == -1)
                status = read_line(fd, &stash);
        if(!stash)
                return NULL;
        line = extract_line(&stash, status);
        if(!line)
        {
                free(stash);
                stash = NULL;
                return NULL;
        }
        return (line);
}
