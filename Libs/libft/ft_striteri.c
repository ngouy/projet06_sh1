/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:27:15 by ngouy             #+#    #+#             */
/*   Updated: 2014/11/13 12:20:19 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	char			*pt;

	if (!s || !f)
		return ;
	i = 0;
	pt = s;
	while (s[i])
	{
		f(i, pt);
		i++;
		pt++;
	}
}
