/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:06:26 by msoklova          #+#    #+#             */
/*   Updated: 2024/04/03 14:42:56 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = s;
	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	int		temp;

	temp = count * size;
	if (count && size && (temp / count != size))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_read(int fd, char *txt)
{
	int		b_read;
	char	*buff;
	char	*temp;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	b_read = read(fd, buff, BUFFER_SIZE);
	while (b_read > 0)
	{
		buff[b_read] = '\0';
		temp = ft_strjoin(txt, buff);
		free(txt);
		txt = temp;
		if (ft_strchr(txt, '\n'))
			break ;
		b_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (b_read <= 0 && !*txt)
	{
		return (NULL);
	}
	return (txt);
}

char	*ft_remaining(char *txt)
{
	char	*str;
	char	*temp;

	str = ft_strchr(txt, '\n');
	if (str)
	{
		*str = '\0';
		temp = ft_strdup(str + 1);
	}
	else
		temp = NULL;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;

	if (str == NULL)
		str = ft_strdup("");
	temp = ft_read(fd, str);
	if (temp == NULL)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = ft_remaining(temp);
	return (temp);
}
