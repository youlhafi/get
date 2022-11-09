#include "get_next_line.h"
# define BUFFER_SIZE 1
#include <stdio.h>

char    *ft_read(int fd, char **s)
{
        char *buff;
        ssize_t r_bytes;

        buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if (!buff)
                return (NULL);
        r_bytes = 1;
        while(r_bytes)
        {
                r_bytes = read(fd,buff,BUFFER_SIZE);
                if (r_bytes == -1)
                {
                        free(buff);
                        return (NULL);
                }
                buff[r_bytes] = 0;
                s[fd] = ft_strjoin(s[fd],buff);
                if (strchr(s[fd],'\n'))
                        break ;
        }
        free (buff);
        return (s[fd]);
}

char    *ft_one_line(char *s)
{
        char *line;
        int i;

        i = 0;
        if (!s[i])
                return (NULL);
        while (s[i] != '\n' && s[i])
                i++;
        line = malloc(sizeof(char) * (i + 2));
        if (!line)
                return (NULL);
        i = 0;
        while(s[i] != '\n' && s[i])
        {
                line[i] = s[i];
                i++;
        }
        if (s[i] == '\n')
        {
                line[i] = s[i];
                i++;
        }
        line[i] = '\0';
        return (line);
}

char    *ft_left(char *rest)
{
        char    *left;
        int             i;
        int             j;

        i = 0;
        j = 0;
        while(rest[i] != '\n' && rest[i])
                i++;
        if(!left)
        {
                free(rest);
                return (NULL);
        }
        left = malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
        if (!left)
                return (NULL);
        i++;
        while(rest[i])
                left[j++] = rest[i++];
        left[j] = '\0';
//      left = ft_substr(rest,i,(ft_strlen(rest) - i));
        free(rest);
        return (left);
}

char    *ft_get_next_line(int fd)
{
        static char *rest[1024];
        char            *line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
        rest[fd] = ft_read(fd,rest);
        if (!rest)
                return (NULL);
        line = ft_one_line(rest[fd]);
        if (!line)
                return (NULL);
        rest[fd] = ft_left(rest[fd]);
        if (!rest[fd])
        {
                free(line);
                return (NULL);
        }
        return (line);
}

int main(void)
{
        int fd;
        fd = open("test",O_RDONLY);
	int fd2;
	fd2 = open("test2",O_RDONLY);
        char *st;
	char *st1;
        int j = 1;
	int fd3;
	fd3= open("test5",O_RDONLY);
	char *st3;
        while (j < 4)
        {
        st = ft_get_next_line(fd);
        printf("line [%d] fd [%d]:%s",j,fd,st);
	st1 = ft_get_next_line(fd2);
	printf("line[%d] fd[%d]:%s",j,fd2,st1);
	st3 = ft_get_next_line(fd3);
	printf("line[%d] fd[%d]:%s",j,fd3,st3);
	free(st1);
        free(st);
	free(st3);
        j++;
        }
	close(fd);
	close(fd2);
	close(fd3);
        //ft_get_next_line(fd);
        return (0);
}

