/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:34:29 by oukhiar           #+#    #+#             */
/*   Updated: 2024/11/29 14:49:11 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next-line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && count > ((size_t)-1) / size)
		return (0);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*po;
	size_t			i;

	i = 0;
	po = (unsigned char *)b;
	while (i < len)
	{
		po[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	char	*base_new;
	size_t	len_total;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_total = ft_strlen(s1) + ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * len_total + 1);
	if (new_string == NULL)
		return (NULL);
	base_new = new_string;
	while (*s1)
		*new_string++ = *s1++;
	while (*s2)
		*new_string++ = *s2++;
	*new_string = '\0';
	return (base_new);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
