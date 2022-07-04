/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 06:18:30 by melkholy          #+#    #+#             */
/*   Updated: 2022/07/04 06:02:53 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count ++;
	return (count);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	int		count;

	count = 0;
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	while (count < (int)(nmemb * size))
	{
		((unsigned char *)array)[count] = '\0';
		count ++;
	}
	return (array);
}

void	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	count;

	count = 0;
	if (n > 0)
	{
		while (count < (n - 1) && src[count])
		{
			dest[count] = src[count];
			count ++;
		}
		dest[count] = '\0';
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	nstr = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!nstr)
		return (NULL);
	ft_strlcpy(nstr, s1, len_s1 + 1);
	ft_strlcpy(&nstr[len_s1], s2, len_s2 + 1);
	free((char *)s1);
	return (nstr);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	count;
	size_t	len;

	len = ft_strlen(str);
	dup = (char *)ft_calloc((len + 1), sizeof(char));
	if (dup == NULL)
		return (NULL);
	count = 0;
	while (count < len)
	{
		dup[count] = str[count];
		count ++;
	}
	dup[count] = '\0';
	return (dup);
}
