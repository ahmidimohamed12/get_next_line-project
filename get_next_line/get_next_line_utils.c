/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 20:45:35 by helkhatr          #+#    #+#             */
/*   Updated: 2019/11/09 22:59:54 by helkhatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i] != '\0')
		i++;
	j = 0;
	while (s2[j] != '\0')
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	i = 0;
	find = c;
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int cpt;

	cpt = 0;
	while (src[cpt] != '\0' && cpt < len)
	{
		dst[cpt] = src[cpt];
		cpt++;
	}
	while (cpt < len)
	{
		dst[cpt] = '\0';
		cpt++;
	}
	return (dst);
}

void	*ft_calloc(unsigned int nitems)
{
	char	*d;
	int		k;

	k = 0;
	d = (char *)malloc(nitems);
	if (d == NULL)
	{
		return (NULL);
	}
	while ((int)nitems > k)
	{
		d[k] = '\0';
		k++;
	}
	return (d);
}
