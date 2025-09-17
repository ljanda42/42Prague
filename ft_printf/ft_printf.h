/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljanda <ljanda@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 08:17:22 by ljanda            #+#    #+#             */
/*   Updated: 2025/09/26 08:31:59 by ljanda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void		ft_put_hex(unsigned int num, const char format);
void		ft_put_ptr(size_t nb);
int			ft_len(int n);
int			hex_len(unsigned int num);
int			len_ptr(size_t nb);
int			ft_unsigned_len(unsigned int nb);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_puthex(unsigned int num, const char format);
int			ft_putptr(size_t ptr);
int			ft_putunsigned(unsigned int nb);
int			ft_conversion(va_list vl, const char format);
int			ft_printf(const char *format, ...);
char		*ft_char(char *s, unsigned int number, int len);
char		*ft_itoa(int n);
char		*ft_uitoa(unsigned int nb);

#endif
