/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:57:44 by youlhafi          #+#    #+#             */
/*   Updated: 2022/11/09 02:24:06 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define BUFFER_SIZE 100
#include <stdio.h>

char	*ft_read(int fd, char *s)
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
		s = ft_strjoin(s,buff);
		if (strchr(s,'\n'))
			break ;
	}
	free (buff);
	return (s);
}

char	*ft_one_line(char *s)
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

char	*ft_left(char *rest)
{
	char	*left;
	int		i;
	int		j;

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
//	left = ft_substr(rest,i,(ft_strlen(rest) - i));
	free(rest);
	return (left);
}
char	*ft_get_next_line(int fd)
{
	static char *rest;
	char 		*line;
	
	rest = ft_read(fd,rest);
	if (!rest)
		return (NULL);
	line = ft_one_line(rest);
	if (!line)
		return (NULL);
	rest = ft_left(rest);
	if (!rest)
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
	char *st;
	int fd2;
	fd2 = open("test2",O_RDONLY);
	char *st2;
	int j = 1;
	while (j < 6)
	{	
	st = ft_get_next_line(fd);
	printf("line [%d] fd [%d]:%s",j,fd,st);
	st2 = ft_get_next_line(fd);
	printf("line [%d] fd [%d]:%s",j,fd2,st);
	free(st);
	free(st2);
	j++;
	}
	close(fd2);
	close(fd);
	//ft_get_next_line(fd);
	return (0);
}
