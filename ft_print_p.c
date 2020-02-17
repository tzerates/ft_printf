/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:55:53 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/17 16:52:49 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_print_p(t_flags mine, va_list argp)
{
	int					i;
	unsigned long int	nb;
	char				*base;

	i = -1;
	base = "0123456789abcdef";
	nb = va_arg(argp, long);
	if (nb == 0 && mine.prec == 0)
	{
		ft_putstr("0x");
		mine.length += 2;
		return (mine);
	}
	if (mine.width - 1 < ft_16(nb))
	{
		write(1, "0x", 2);
		ft_putnbr_base(nb, base, ft_16(nb), mine);
	}
	if (mine.width > ft_16(nb) && mine.minus == 0)
	{
		while (++i < mine.width - ft_16(nb) - 2)
			ft_putchar(' ');
		write(1, "0x", 2);
		ft_putnbr_base(nb, base, ft_16(nb), mine);
	}
	else if (mine.minus == 1 && mine.width > ft_16(nb))
	{
		write(1, "0x", 2);
		ft_putnbr_base(nb, base, ft_16(nb), mine);
		while (++i < mine.width - ft_16(nb) - 2)
			ft_putchar(' ');
	}
	mine.length += mine.width > ft_16(nb) ? mine.width : ft_16(nb) + 2;
	mine.length += mine.width == ft_16(nb) + 1 ? 1 : 0;
	return (mine);
}
