/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:15:02 by youlhafi          #+#    #+#             */
/*   Updated: 2022/11/09 02:21:19 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	new = malloc(sizeof(char) * len + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j] && i < len)
	{
		if (j >= start && i < len)
		{
			new[i] = s[j];
			i++;
		}
		j++;
	}
	new[i] = '\0';
	return (new);
}
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i + 1]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i + 1]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
  //  free((char *)s);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;
    if (!s1)
    {
        s1 = malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	j = 0;
   // if(s1)
   // {
	    while (s1[i])
	    {
		    new[i] = s1[i];
		    i++;
	    }
    //}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    	free(s1);
	return (new);
}
 
