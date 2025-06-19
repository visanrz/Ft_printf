/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_supplies.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorsa <victorsa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:03:34 by victorsa          #+#    #+#             */
/*   Updated: 2025/06/04 14:03:34 by victorsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long n)
{
	long		num;
	int			len;
	int			aux;

	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len += 1;
		n *= -1;
	}
	num = n % 10 + '0';
	if (n > 9)
	{
		aux = ft_putnbr(n / 10);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	if (write(1, &num, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*s != '\0')
	{
		if (write(1, s, 1) == -1)
			return (-1);
		len++;
		s++;
	}
	return (len);
}

int	ft_putnbr_hexa(unsigned long nbr, char up)
{
	int		len;
	int		mod;
	char	*base;
	int		aux;

	mod = 0;
	len = 0;
	if (up == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
	{
		aux = ft_putnbr_hexa((nbr / 16), up);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	mod = nbr % 16;
	if (write(1, &base[mod], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	aux;

	len = 0;
	aux = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	aux = ft_putnbr_hexa((unsigned long)ptr, 'x');
	if (aux == -1)
		return (-1);
	len += aux;
	return (len);
}
