/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanda <ljanda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 08:17:22 by ljanda            #+#    #+#             */
/*   Updated: 2025/09/26 08:31:59 by ljanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		len;

	len = ft_unsigned_len(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (nb != 0)
	{
		str[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (str);
}

int	ft_putunsigned(unsigned int nb)
{
	int		char_printed;
	char	*str;

	char_printed = 0;
	if (nb == 0)
		char_printed += write(1, "0", 1);
	else
	{
		str = ft_uitoa(nb);
		char_printed += ft_putstr(str);
		free(str);
	}
	return (char_printed);
}
