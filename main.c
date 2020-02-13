/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzerates <tzerates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 15:35:13 by tzerates          #+#    #+#             */
/*   Updated: 2020/02/13 20:42:20 by tzerates         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main ()
{
    char *test;
    char test1;
    int  count;
    
    count = 12;
    test1 = 48;
    //test = "gavin";
    //printf("hello, %s." "%s", "gavin", "test");
   //ft_printf("hello, %10.15s." "%s", "gavin", test);
    ft_printf("hello, %s.", "gavin");
    return (0);
}

/*	printf("zero :%d\n", mine.zero);
	printf("minus :%d\n", mine.minus);
	printf("width :%d\n", mine.width);
	printf("prec :%d\n", mine.prec);
	printf("length :%d\n", mine.length);*/
