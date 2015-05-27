/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 14:52:46 by ngouy             #+#    #+#             */
/*   Updated: 2014/11/25 16:59:00 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	if (s)
	{
		str = (char *)s;
		while (n > 0)
		{
			if (*str == (char)c)
				return ((void *)str);
			n--;
			str++;
		}
	}
	return (NULL);
}
