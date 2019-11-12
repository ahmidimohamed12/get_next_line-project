/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:40:57 by helkhatr          #+#    #+#             */
/*   Updated: 2019/11/10 13:27:53 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char *fr;

	if (!s)
		return (NULL);
	fr = (char*)malloc(sizeof(char) * (len + 1));
	if (!fr)
		return (0);
	fr = ft_strncpy(fr, s + start, len);
	return (fr);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*phr;

	if (!s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	phr = ft_calloc(i + 1);
	if (phr == NULL)
		return (NULL);
	phr = ft_strcat(phr, (char*)s1);
	phr = ft_strcat(phr, (char*)s2);
	return (phr);
}

static int		gnl(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *s1)
{
	int			r;
	char		*ptr;

	r = 0;
	if ((ptr = (char*)malloc(sizeof(char) * (ft_strlen(s1)) + 1)) == NULL)
		return (0);
	while (s1[r] != '\0')
	{
		ptr[r] = s1[r];
		r++;
	}
	ptr[r] = '\0';
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	int				r;
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	int				i;

	r = 0;
	if (fd < 0 || read(fd, buff, 0) || !line || fd > 4864)
		return (-1);
	if (!str)
		str = (char *)malloc(sizeof(char) * 0);
	while ((!ft_strchr(str, '\n')) && (r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp  = ft_strjoin(str, buff);
		free(str);
		str = tmp;
	}
	 if (r < 1 && !*str && !gnl(str))
	 	return (r);
	i = 0;
	*line = ft_strsub(str, 0, gnl(str));
	i = gnl(str);
	if (str[i]  == '\n')
		tmp = ft_strdup(&str[i + 1]);
	else
		tmp = ft_strdup("");
	free(str);
	str = tmp;
	return (1);
}
