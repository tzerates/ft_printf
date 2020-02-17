/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 20:26:21 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/17 19:36:31 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_print_u1(t_flags mine, int len, unsigned int nb, int k)
{
	int i;

	i = -1;
	if (mine.prec == -1 ||
	(mine.width >= len && mine.prec >= len))
		ft_putnbr(nb, mine.prec, ft_lgth(nb), mine);
	if (mine.prec < len && mine.prec != -1)
	{
		ft_putnbr(nb, mine.prec, ft_lgth(nb), mine);
		while (++i < mine.width - len)
			ft_putchar(' ');
	}
	else
		while (++i < mine.width - k)
			ft_putchar(' ');
}

static void			ft_print_u0(t_flags mine, unsigned int nb, int k)
{
	int i;

	i = -1;
	if (mine.prec < ft_lgth(nb) && mine.prec != -1)
	{
		while (++i < mine.width - ft_lgth(nb))
			ft_putchar(' ');
		ft_putnbr(nb, mine.prec, ft_lgth(nb), mine);
	}
	else
		while (++i < mine.width - k)
			ft_putchar(' ');
	if ((mine.prec == -1) ||
		(mine.width >= ft_lgth(nb) && mine.prec >= ft_lgth(nb)))
		ft_putnbr(nb, mine.prec, ft_lgth(nb), mine);
}

static void			ft_print_u2(t_flags mine, unsigned int nb, int k)
{
	int i;

	i = -1;
	if (mine.prec < ft_lgth(nb) && mine.prec != -1)
	{
		while (++i < mine.width - ft_lgth(nb))
			ft_putchar(' ');
		ft_putnbr(nb, mine.prec, ft_lgth(nb), mine);
	}
	else if (mine.prec != -1)
		while (++i < mine.width - k)
			ft_putchar(' ');
	else if (mine.width > mine.prec && mine.prec != -1)
		while (++i < mine.width - k - 1)
			ft_putchar(' ');
	if ((mine.prec == -1) ||
		(mine.width >= ft_lgth(nb) && mine.prec >= ft_lgth(nb)))
		ft_putnbr(nb, mine.prec, ft_lgth(nb), mine);
}

t_flags				ft_print_u(t_flags mine, va_list argp)
{
	unsigned int	nb;
	int				i;
	int				k;

	i = -1;
	nb = va_arg(argp, unsigned int);
	k = mine.prec >= ft_lgth(nb) ? mine.prec : ft_lgth(nb);
	if (nb == 0 && mine.prec == 0)
	{
		while (++i < mine.width)
			ft_putchar(' ');
		mine.length += mine.width;
		return (mine);
	}
	if (mine.minus == 1)
		ft_print_u1(mine, ft_lgth(nb), nb, k);
	if (mine.minus == 0 && mine.zero == 0)
		ft_print_u0(mine, nb, k);
	if (mine.minus == 0 && mine.zero == 1)
		ft_print_u2(mine, nb, k);
	if (mine.prec >= ft_lgth(nb) && mine.width < ft_lgth(nb))
		ft_putnbr(nb, mine.prec, ft_lgth(nb), mine);
	mine.length += k > mine.width ? k : mine.width;
	return (mine);
}
