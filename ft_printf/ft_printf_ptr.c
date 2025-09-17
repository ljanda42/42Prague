/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanda <ljanda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 08:17:22 by ljanda            #+#    #+#             */
/*   Updated: 2025/09/26 08:31:59 by ljanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_ptr(size_t nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	ft_put_ptr(size_t nb)
{
	if (nb >= 16)
		ft_put_ptr(nb / 16);
	if (nb % 16 <= 9)
		ft_putchar((nb % 16) + '0');
	else
		ft_putchar((nb % 16 - 10) + 'a');
}

int	ft_putptr(size_t ptr)
{
	int	char_printed;

	if (ptr == 0)
		return (write(1, "(nil)", 5));
	char_printed = 0;
	char_printed += write(1, "0x", 2);
	ft_put_ptr(ptr);
	char_printed += len_ptr(ptr);
	return (char_printed);
}
