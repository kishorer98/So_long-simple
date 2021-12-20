/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:39:53 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/14 12:52:23 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *to, const void *from, size_t numBytes)
{
	char	*pto;
	char	*pfrom;

	pto = (char *)to;
	pfrom = (char *)from;
	if (to == NULL && from == NULL)
		return (NULL);
	while (numBytes--)
	{
		*pto = *pfrom;
		pfrom++;
		pto++;
	}
	return (to);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*rslt;

	size = ft_strlen(s);
	rslt = malloc(size + 1);
	if (rslt == NULL)
		return (NULL);
	ft_memcpy(rslt, (unsigned char *)s, size);
	rslt[size] = 0;
	return (rslt);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

static void	copyinpos(char *dest, char const *src, size_t start)
{
	size_t	pos;

	pos = 0;
	while (src[pos] != '\0')
	{
		dest[start] = src[pos];
		start++;
		pos++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fullstring;
	size_t	totallen;

	totallen = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fullstring = malloc(totallen + 1);
	if (fullstring == NULL)
		return (NULL);
	copyinpos(fullstring, s1, 0);
	copyinpos(fullstring, s2, ft_strlen(s1));
	fullstring[totallen] = 0;
	return (fullstring);
}
