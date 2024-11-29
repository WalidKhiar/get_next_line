/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukhiar <oukhiar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:34:29 by oukhiar           #+#    #+#             */
/*   Updated: 2024/11/29 22:09:01 by oukhiar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	char	*base_sub;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	sub_str = (char *)malloc(sizeof(char) * len + 1);
	if (sub_str == NULL)
		return (NULL);
	base_sub = sub_str;
	s += start;
	while (len > 0)
	{
		*sub_str++ = *s++;
		len--;
	}
	*sub_str = '\0';
	return (base_sub);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

char	*ft_strdup(const char *s1)
{
	char	*base_s2;
	size_t	s_len;
	char	*s2;

	s_len = ft_strlen(s1);
	s2 = (char *)malloc(s_len * sizeof(char) + 1);
	if (!s2)
		return (NULL);
	base_s2 = s2;
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (base_s2);
}

