/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx_ft_printf_xx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:31:58 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/17 19:35:41 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			xx_ft_print1_xx(t_flags mine, long nb, int k, char *base)
{
	int i;

	i = -1;
	if (mine.prec == -1 ||
	(mine.width >= ft_16(nb) && mine.prec >= ft_16(nb)))
		ft_putnbr_base(nb, base, ft_16(nb), mine);
	if (mine.prec < ft_16(nb) && mine.prec != -1)
	{
		ft_putnbr_base(nb, base, ft_16(nb), mine);
		while (++i < mine.width - ft_16(nb))
			ft_putchar(' ');
	}
	else
		while (++i < mine.width - k)
			ft_putchar(' ');
}

static void			xx_ft_print0_xx(t_flags mine, long nb, int k, char *base)
{
	int i;

	i = -1;
	if (mine.prec < ft_16(nb) && mine.prec != -1)
	{
		while (++i < mine.width - ft_16(nb))
			ft_putchar(' ');
		ft_putnbr_base(nb, base, ft_16(nb), mine);
	}
	else
		while (++i < mine.width - k)
			ft_putchar(' ');
	if ((mine.prec == -1) ||
		(mine.width >= ft_16(nb) && mine.prec >= ft_16(nb)))
		ft_putnbr_base(nb, base, ft_16(nb), mine);
}

static void			xx_ft_print2_xx(t_flags mine, long nb, int k, char *base)
{
	int i;

	i = -1;
	if (mine.prec < ft_16(nb) && mine.prec != -1)
	{
		while (++i < mine.width - ft_16(nb))
			ft_putchar(' ');
		ft_putnbr_base(nb, base, ft_16(nb), mine);
	}
	else if (mine.prec != -1)
		while (++i < mine.width - k)
			ft_putchar(' ');
	else if (mine.width > mine.prec && mine.prec != -1)
		while (++i < mine.width - k - 1)
			ft_putchar(' ');
	if ((mine.prec == -1) ||
		(mine.width >= ft_16(nb) && mine.prec >= ft_16(nb)))
		ft_putnbr_base(nb, base, ft_16(nb), mine);
}

static	void		ft_25_lignes(t_flags mine)
{
	int i;

	i = -1;
	while (++i < mine.width)
		ft_putchar(' ');
}

t_flags				xx_ft_print_xx(t_flags mine, va_list argp, char c)
{
	long	nb;
	int		k;
	char	*base;

	base = c == 120 ? "0123456789abcdef" : "0123456789ABCDEF";
	nb = va_arg(argp, unsigned int);
	k = mine.prec >= ft_16(nb) ? mine.prec : ft_16(nb);
	if (nb == 0 && mine.prec == 0)
	{
		ft_25_lignes(mine);
		mine.length += mine.width;
		return (mine);
	}
	if (mine.minus == 1)
		xx_ft_print1_xx(mine, nb, k, base);
	if (mine.minus == 0 && mine.zero == 0)
		xx_ft_print0_xx(mine, nb, k, base);
	if (mine.minus == 0 && mine.zero == 1)
		xx_ft_print2_xx(mine, nb, k, base);
	if (mine.prec >= ft_16(nb) && mine.width < ft_16(nb))
		ft_putnbr_base(nb, base, ft_16(nb), mine);
	mine.length += k > mine.width ? k : mine.width;
	return (mine);
}
