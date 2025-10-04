/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanda <ljanda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 08:17:22 by ljanda            #+#    #+#             */
/*   Updated: 2025/10/04 08:31:59 by ljanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*newline_exist(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char *buff)
{
	int		i;
	int		j;
	char	*temp;

	if (!stash && !buff)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	temp = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buff) + 1));
	if (!temp)
		return (NULL);
	i = -1;
	while (stash[++i])
		temp[i] = stash[i];
	j = -1;
	while (buff[++j])
		temp[i++] = buff[j];
	temp[i] = '\0';
	free(stash);
	free(buff);
	return (temp);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
