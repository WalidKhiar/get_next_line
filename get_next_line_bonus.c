/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:37:04 by oukhiar           #+#    #+#             */
/*   Updated: 2024/12/02 12:55:56 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*res[OPEN_MAX];
	char		*tmp;
	int			newline_index;
	char		*ret;

	read_until_newline(fd, &res[fd], &newline_index);
	if (!res[fd])
		return (NULL);
	if (newline_index == -1)
	{
		ret = res[fd];
		res[fd] = NULL;
		return (ret);
	}
	ret = ft_substr(res[fd], 0, newline_index + 1);
	if (!ret)
		return (NULL);
	tmp = res[fd];
	res[fd] = ft_substr(res[fd], newline_index + 1, INT_MAX);
	if (!res[fd])
		return (NULL);
	free(tmp);
	return (ret);
}

char	*get_next_line(int fd)
{
	char	*res;
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = extract_update(fd);
	return (res);
}
