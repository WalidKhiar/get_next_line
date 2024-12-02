/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:30:04 by oukhiar           #+#    #+#             */
/*   Updated: 2024/12/02 14:56:25 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *res)
{
	int	i;

	i = 0;
	if (!res)
		return (-1);
	while (res[i] != '\0')
	{
		if (res[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	*read_until_newline(int fd, char **res, int *newline_index)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	buff[BUFFER_SIZE + 1];

	*newline_index = check_newline(*res);
	while (*newline_index == -1)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			free (*res);
			*res = NULL;
			return (0);
		}
		buff[bytes_read] = 0;
		tmp = *res;
		*res = ft_strjoin(*res, buff);
		free(tmp);
		if (!*res)
			return (0);
		*newline_index = check_newline(*res);
	}
	return (newline_index);
}

char	*extract_update(int fd)
{
	static char	*res;
	char		*tmp;
	int			newline_index;
	char		*ret;

	read_until_newline(fd, &res, &newline_index);
	if (!res)
		return (NULL);
	if (newline_index == -1)
	{
		ret = res;
		res = NULL;
		return (ret);
	}
	ret = ft_substr(res, 0, newline_index + 1);
	if (!ret)
		return (NULL);
	tmp = res;
	res = ft_substr(res, newline_index + 1, INT_MAX);
	if (!res)
		return (NULL);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = extract_update(fd);
	return (res);
}
