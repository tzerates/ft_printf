/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:29:13 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/17 19:49:41 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_analyzer(const char *s, t_flags mine, va_list argp)
{
	if (s[mine.i] == '%' && s[mine.i + 1])
		mine = ft_set_flags((char *)s, mine, argp);
	if (s[mine.i] == '%')
		mine = ft_print_percent(mine);
	if (s[mine.i] == 'c')
		mine = ft_print_c(mine, argp);
	if (s[mine.i] == 's')
		mine = ft_print_s(mine, argp);
	if (s[mine.i] == 'd' || s[mine.i] == 'i')
		mine = ft_print_id(mine, argp);
	if (s[mine.i] == 'u')
		mine = ft_print_u(mine, argp);
	if (s[mine.i] == 'x' || s[mine.i] == 'X')
		mine = xx_ft_print_xx(mine, argp, s[mine.i]);
	if (s[mine.i] == 'p')
		mine = ft_print_p(mine, argp);
	mine.minus = 0;
	mine.zero = 0;
	mine.width = 0;
	mine.prec = -1;
	return (mine);
}

t_flags		ft_set_flags(char *s, t_flags mine, va_list argp)
{
	while (s[++mine.i] == '-' || s[mine.i] == '0')
	{
		if (s[mine.i] == '-')
			mine.minus = 1;
		if (s[mine.i] == '0')
			mine.zero = 1;
	}
	if (mine.minus == 1)
		mine.zero = 0;
	mine.width = s[mine.i] == '*' ? va_arg(argp, int) : ft_atoi(s + mine.i);
	while ((s[mine.i] >= '0' && s[mine.i] <= '9') || s[mine.i] == '*')
		mine.i++;
	if (s[mine.i] == '.')
		mine.prec = s[mine.i + 1] == '*' ? va_arg(argp, int) :
	ft_atoi(s + mine.i + 1);
	mine = ft_verif(mine);
	while (ft_isdigit(s[mine.i]) || s[mine.i] == '*' || s[mine.i] == '.')
		mine.i++;
	return (mine);
}

t_flags		ft_initialize(void)
{
	t_flags mine;

	mine.minus = 0;
	mine.zero = 0;
	mine.width = 0;
	mine.prec = -1;
	mine.i = 0;
	mine.length = 0;
	return (mine);
}

int			ft_printf(const char *s, ...)
{
	va_list argp;
	t_flags	mine;

	va_start(argp, s);
	mine = ft_initialize();
	while (s[mine.i])
	{
		while (s[mine.i] && s[mine.i] != '%')
		{
			ft_putchar(s[mine.i++]);
			mine.length++;
		}
		if (s[mine.i] == '%')
			mine = ft_analyzer(s, mine, argp);
		if (s[mine.i] == 0)
			break ;
		mine.i++;
	}
	va_end(argp);
	return (mine.length);
}
