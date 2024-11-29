/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:30:04 by oukhiar           #+#    #+#             */
/*   Updated: 2024/11/29 17:16:07 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int check_newline(char *res)
{
	int i;

	i = 0;
	while(res[i] != '\0')
	{
		if (res[i] == '\n')
			return(i);
		i++;
	}
	return(-1);
}

char *get_next_line(int fd)
{
	static char *res;
	int bytes_read;
	int total_bytes_read;
	char buff[BUFFER_SIZE + 1];
	int newline_index = -1;
	
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
	while ((bytes_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bytes_read] = 0;
		// tmp = res;
		res = ft_strjoin(res, buff);
		// free(tmp);
		newline_index = check_newline(res);
		if (newline_index != -1)
			break;
	}
	char *ret;
	if (newline_index == -1)
	{
		ret = res;
		res = 0;
		return ret;
	}

	ret = ft_substr(res, 0, newline_index + 1);
	res = ft_substr(res, newline_index + 1, INT_MAX);

	return (ret);

}

int main ()
{
        int fd = open("test.txt", O_RDONLY | O_CREAT);
        char *res = get_next_line(fd);
		printf()
}