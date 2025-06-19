/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victorsa <victorsa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:13:07 by victorsa          #+#    #+#             */
/*   Updated: 2025/06/04 14:13:07 by victorsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(long n);
int	ft_putnbr_hexa(unsigned long nbr, char up);
int	ft_putptr(void *ptr);
int	ft_putstr(char *s);

#endif