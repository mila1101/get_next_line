/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:56:43 by msoklova          #+#    #+#             */
/*   Updated: 2024/04/05 19:31:12 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (ptr == NULL)
		return (NULL);
	a = ptr;
	while (i < temp)
	{
		a[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_read(int fd, char *txt)
{
	int		b_read;
	char	*buff;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	b_read = read(fd, buff, BUFFER_SIZE);
	while (b_read > 0)
	{
		buff[b_read] = '\0';
		txt = free_strjoin(txt, buff);
		if (!txt || ft_strchr(txt, '\n'))
			break ;
		b_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (b_read == -1 || (b_read <= 0 && !*txt))
		return (NULL);
	return (txt);
}

char	*ft_remaining(char *txt)
{
	char	*str;
	char	*temp;

	str = ft_strchr(txt, '\n');
	if (str)
	{
		temp = ft_strdup(str + 1);
		str[1] = '\0';
	}
	else
		temp = NULL;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*temp;

	if (fd < 0)
		return (NULL);
	if (str[fd] == NULL)
	{
		str[fd] = ft_strdup("");
		if (str[fd] == NULL)
			return (NULL);
	}
	temp = ft_read(fd, str[fd]);
	if (temp == NULL)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_remaining(temp);
	return (temp);
}
