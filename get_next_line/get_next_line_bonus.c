/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:56:54 by helkhatr          #+#    #+#             */
/*   Updated: 2019/11/10 02:56:56 by helkhatr         ###   ########.fr       */
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
	char *tmp;

	if (!s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	phr = ft_calloc(i + 1);
	if (phr == NULL)
		return (NULL);
	tmp = phr;
	phr = ft_strcat(phr, (char*)s1);
	phr = ft_strcat(phr, (char*)s2);
	return (phr);
}

static int		gnl(char **str, int fd)
{
	int i;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char		*str[4864];
	int				i;
	int				r;
	char			buff[BUFFER_SIZE + 1];
	char			**tmp;

	r = 0;
	if (fd < 0 || read(fd, buff, 0) || !line)
		return (-1);
	if (!str[fd])
		str[fd] = (char *)malloc(0);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = &str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		free(*tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	i = gnl(str, fd);
	*line = ft_strsub(str[fd], 0, i);
	if (!i && !ft_strlen(str[fd]) && !r)
		return (0);
	str[fd] = str[fd] + i + 1;
	return (1);
}
