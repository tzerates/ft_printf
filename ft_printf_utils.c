/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:18:49 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/13 14:25:43 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	i = -1;
	if (!s)
		return ;
	while (s[++i])
		ft_putchar(s[i]);
}

void	ft_putnstr(char *s, int n)
{
	int i;

	i = -1;
	if (!s)
		return ;
	while (s[++i] && i < n)
		ft_putchar(s[i]);
}

int		ft_isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}
