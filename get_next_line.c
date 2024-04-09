/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoklova <msoklova@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:06:26 by msoklova          #+#    #+#             */
/*   Updated: 2024/04/09 15:42:59 by msoklova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_read(int fd, char *txt)
{
	int		b_read;
	char	*buff;

	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
	{
		free(txt);
		return (NULL);
	}
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
	if (b_read == -1 || (b_read == 0 && !*txt))
	{
		free(txt);
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
		temp = ft_strdup(str + 1);
		if (temp == NULL)
			return (NULL);
		str[1] = '\0';
	}
	else
		temp = NULL;
	return (temp);
}

char	*update_txt(char *txt)
{
	int		count;
	char	*str;
	char	*temp;

	count = 0;
	temp = txt;
	while (txt[count] != '\n' && txt[count])
		count++;
	if (txt[count] == '\n')
		count++;
	str = ft_calloc(count + 1, sizeof(char));
	if (str == NULL)
	{
		free(txt);
		return (NULL);
	}
	count = 0;
	while (*txt != '\n' && *txt)
		str[count++] = *txt++;
	if (*txt == '\n')
		str[count++] = *txt;
	str[count] = '\0';
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;

	if (str == NULL)
	{
		str = ft_strdup("");
		if (str == NULL)
			return (NULL);
	}
	temp = ft_read(fd, str);
	if (temp == NULL)
	{
		str = NULL;
		return (NULL);
	}
	str = ft_remaining(temp);
	temp = update_txt(temp);
	if (temp == NULL)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (temp);
}
