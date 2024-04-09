/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:57:24 by msoklova          #+#    #+#             */
/*   Updated: 2024/04/09 16:33:58 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
	{
		free((void *)s1);
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	free((void *)s1);
	return (join);
}

char	*ft_strdup(const char *s1)
{
	size_t			len;
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	size_t			temp;
	unsigned char	*a;
	size_t			i;

	i = 0;
	temp = count * size;
	if (count && size && (temp / count != size))
		return (NULL);
	ptr = malloc(temp);
	if (!ptr)
		return (NULL);
	a = ptr;
	while (i < temp)
	{
		a[i] = 0;
		i++;
	}
	return (ptr);
}
