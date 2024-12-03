/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:37:04 by oukhiar           #+#    #+#             */
/*   Updated: 2024/12/03 13:06:58 by oukhiar          ###   ########.fr       */
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

void	ft_reducing(int fd, char ***res, int *newline_index, char **buff)
{
	ssize_t	bytes_read;
	char	*tmp;

	while (*newline_index == -1)
	{
		bytes_read = read(fd, *buff, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
		{
			free (**res);
			**res = NULL;
			break ;
		}
		(*buff)[bytes_read] = 0;
		tmp = **res;
		**res = ft_strjoin(**res, *buff);
		if (!**res)
		{
			free(tmp);
			break ;
		}
		free(tmp);
		*newline_index = check_newline(**res);
	}
}

void	read_until_newline(int fd, char **res, int *newline_index)
{
	char	*buff;

	*newline_index = check_newline(*res);
	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return ;
	ft_reducing(fd, &res, newline_index, &buff);
	free (buff);
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

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	res = extract_update(fd);
	return (res);
}

// int main()
// {
// 	int a = open("get_next_line.c", O_RDONLY | O_CREAT);
// 	int fd = open("get_next_line.h",O_RDONLY | O_CREAT);
// 	int i = 0;
// 	int j = 0;
// 	char *line;
// 	while (i < 50)
// 	{
// 		line = get_next_line(a);
// 		printf("line.c N[%d] : %s", i, line);
// 		free (line);
// 		line = get_next_line(fd);
// 		printf("line.h N[%d] : %s", j, line);
// 		free (line);
// 		i++;
// 		j++;
// 	}
// 	close (a);
// 	close(fd);
// 		return (0);
// }