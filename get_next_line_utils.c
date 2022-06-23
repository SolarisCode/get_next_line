/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:17:04 by melkholy          #+#    #+#             */
/*   Updated: 2022/06/23 23:21:48 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findendl(const char *str, int c)
{
	int	count;

	count = 0;
	while (str[count] && str[count] != (unsigned char)c)
		count ++;
	if (str[count] == (unsigned char)c)
		return (count);
	return (0);
}

char	*ft_sub_toline(char *s)
{
	char	*sub;
	size_t	count;
	size_t	end;

	end = ft_findendl(s, '\n');
	if (!end)
		return (NULL);
	sub = (char *)malloc(end * sizeof(char) + 2);
	if (!sub)
		return (NULL);
	count = 0;
	while (count <= end)
	{
		sub[count] = s[count];
		count ++;
	}
	sub[count] = '\0';
	return (sub);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	count;
	size_t	len;

	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
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
