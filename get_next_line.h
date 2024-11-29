/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:31:07 by oukhiar           #+#    #+#             */
/*   Updated: 2024/11/29 22:02:37 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <fcntl.h>
# include <stddef.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 42

char *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
#endif