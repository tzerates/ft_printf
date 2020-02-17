/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:45:55 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/17 19:33:56 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr(long long nb, int prec, int len, t_flags mine)
{
	long int	nbr;
	long int	mod;
	long int	div;

	nbr = nb;
	if (prec == -1 && mine.width)
		prec = nbr >= 0 ? mine.width : mine.width - 1;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
		len--;
	}
	if (mine.prec != -1 ||
		(mine.prec == -1 && mine.width > ft_lgth(nb) && mine.zero))
		while (prec > len)
		{
			ft_putchar('0');
			prec--;
		}
	mod = nbr % 10;
	div = nbr / 10;
	if (div)
		ft_putnbr(div, prec, len, mine);
	ft_putchar(mod + 48);
}

int			ft_16(unsigned long int nb)
{
	if (nb > 15)
		return (1 + ft_16(nb / 16));
	return (1);
}

void		ft_putnbr_base(unsigned long nbr, char *base, int len, t_flags mine)
{
	long long int	div;
	long long int	mod;

	if (mine.prec != -1)
		while (mine.prec > len)
		{
			ft_putchar('0');
			mine.prec--;
		}
	if (mine.prec == -1 && mine.width >= ft_16(nbr) && mine.zero)
		while (mine.width > len)
		{
			ft_putchar('0');
			mine.width--;
		}
	mod = nbr % 16;
	div = nbr / 16;
	if (div)
		ft_putnbr_base(div, base, len, mine);
	ft_putchar(base[mod]);
}

t_flags		ft_verif(t_flags mine)
{
	if (mine.width < 0)
	{
		mine.width *= -1;
		mine.minus = 1;
		mine.zero = 0;
	}
	if (mine.prec < 0)
		mine.prec = -1;
	return (mine);
}

t_flags		ft_len_s(t_flags mine, char *str)
{
	if (mine.prec == -1 && mine.width > 0 && str)
		mine.length += mine.width > ft_len(str) ? mine.width : ft_len(str);
	if (mine.width == 0 && mine.prec != -1 && str)
		mine.length += mine.prec > ft_len(str) ? ft_len(str) : mine.prec;
	if (mine.prec != -1 && mine.width > 0 && str)
	{
		if (mine.prec > mine.width && mine.prec >= ft_len(str))
			mine.length += mine.width < ft_len(str) ? ft_len(str) : mine.width;
		else if (mine.prec > mine.width && mine.prec < ft_len(str))
			mine.length += mine.width < ft_len(str) ? mine.prec : mine.width;
		else
			mine.length += mine.width;
	}
	if (mine.width == 0 && mine.prec == -1 && str)
		mine.length += ft_len(str);
	if (!str)
		mine.length += mine.width;
	return (mine);
}
