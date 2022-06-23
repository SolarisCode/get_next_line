/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:34:35 by melkholy          #+#    #+#             */
/*   Updated: 2022/06/23 23:36:16 by melkholy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count ++;
	return (count);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (unsigned char)c)
		str ++;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	count_d;
	size_t	count_s;
	size_t	dst_len;

	count_s = 0;
	count_d = ft_strlen(dst);
	dst_len = count_d;
	if (n <= dst_len)
		return (n + ft_strlen(src));
	while (src[count_s] != '\0')
	{
		if (count_d < (n - 1))
		{
			dst[count_d] = src[count_s];
			count_d ++;
		}
		count_s ++;
	}
	dst[count_d] = '\0';
	return (dst_len + count_s);
}

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = '\0';
		s ++;
		n --;
	}
}

char	*get_next_line(int fd)
{
	static char	line[500];
	char		*str;
	char		*rmn;
	int			bytes;

	if (!(rmn = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1)))
		return (NULL);
	bytes = read(fd, rmn, BUFFER_SIZE);
	rmn[bytes] = '\0';
	ft_strlcat(line, rmn, 500);
	if ((str = ft_sub_toline((char *)line)))
	{
		free(rmn);
		rmn = ft_strdup((ft_strchr((const char *)line, '\n')) + 1);
		ft_bzero(line, 500);
		ft_strlcat(line, rmn, 500);
		free(rmn);
		return (str);
	}
	else if (!(ft_strchr((const char *)line, '\n')) && !bytes)
	{
		free(rmn);
		return (ft_strdup(line));
	}
	free(rmn);
	return (get_next_line(fd));
}

int	main(void)
{
	int		fd;
	char	*ptr;

	fd = open("test.txt", O_RDWR);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("%s", ptr);
	free(ptr);
	return (0);
}
