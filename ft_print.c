/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:42:59 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/13 19:49:32 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_print_c(t_flags mine, va_list argp)
{
	int i;

	i = -1;
	if (mine.width == 1)
		ft_putchar(va_arg(argp, int));
	if (mine.minus == 0 && mine.width != 1)
	{
		while (++i < mine.width - 1)
			ft_putchar(' ');
		ft_putchar(va_arg(argp, int));
	}
	else if (mine.minus == 1 && mine.width != 1)
	{
		ft_putchar(va_arg(argp, int));
		while (++i < mine.width - 1)
			ft_putchar(' ');
	}
	mine.length += mine.width;
	return (mine);
}

t_flags	ft_print_s(t_flags mine, va_list argp)
{
	char	*str;
	int		i;

	i = -1;
	str = va_arg(argp, void *);
	if (mine.minus == 1)
	{
		if ((mine.width > ft_len(str) && mine.prec == -1) ||
			(mine.width > ft_len(str) && mine.prec > ft_len(str)))
			ft_putstr(str);
		if (mine.prec < ft_len(str) && mine.prec != -1)
		{
			ft_putnstr(str, mine.prec);
			while (++i < mine.width - mine.prec)
				ft_putchar(' ');
		}
		else
		{
			while (++i < mine.width - ft_len(str))
				ft_putchar(' ');
		}
	}
	if (mine.minus == 0)
	{
		if (mine.prec < ft_len(str) && mine.prec != -1)
		{
			while (++i < mine.width - mine.prec)
				ft_putchar(' ');
			ft_putnstr(str, mine.prec);
		}
		else
		{
			while (++i < mine.width - ft_len(str))
				ft_putchar(' ');
		}
		if ((mine.width > ft_len(str) && mine.prec == -1) ||
			(mine.width > ft_len(str) && mine.prec > ft_len(str)))
			ft_putstr(str);
		//if (mine.width > ft_len(str) && mine.prec < ft_len(str))
		//	ft_putnstr(str, mine.prec);
	}
	if ((mine.prec == -1 || mine.prec > ft_len(str)) &&
		mine.width < ft_len(str))
		ft_putstr(str);
	//if (mine.prec > 0 && mine.prec < ft_len(str) && mine.width == 0)
	//	ft_putnstr(str, mine.prec);
	mine.length += ft_len(str);
	return (mine);
}
