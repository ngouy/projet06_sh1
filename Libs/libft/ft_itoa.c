/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:12:33 by ngouy             #+#    #+#             */
/*   Updated: 2014/11/25 17:35:37 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_letsgo(int n, int *sign, char **ret)
{
	if (n >= 10)
	{
		ft_letsgo(n / 10, sign, ret);
		(*sign)++;
		(*ret)[*sign] = n % 10 + 48;
	}
	else
		(*ret)[*sign] = n + 48;
}

static char		*ft_troll(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 10 + 1);
	ret[0] = '-';
	ret[1] = '2';
	ret[2] = '1';
	ret[3] = '4';
	ret[4] = '7';
	ret[5] = '4';
	ret[6] = '8';
	ret[7] = '3';
	ret[8] = '6';
	ret[9] = '4';
	ret[10] = '8';
	return (ret);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		sign;

	if (n == -2147483648)
		return (ft_troll());
	sign = 0;
	ret = ft_strnew(11);
	if (n < 0)
	{
		ret[0] = '-';
		n = -n;
		sign = 1;
	}
	ft_letsgo(n, &sign, &ret);
	return (ret);
}
