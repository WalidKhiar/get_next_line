/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:30:04 by oukhiar           #+#    #+#             */
/*   Updated: 2024/11/29 15:23:32 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *res;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
	/*
	while (there is no newline in the `res` and there is something to read (read doesn't return 0))
		read from the fd by BUFFER_SIZE
	
	extract the string from 0 up to \n if any (if not up to the end)
	

	update the `res` to contain only the rest of what you have read

	return the extracted string

	*/	

}

int main ()
{
        int fd = open("test.txt", O_RDONLY | O_CREAT);
        char *res = get_next_line(fd);
		printf()
}