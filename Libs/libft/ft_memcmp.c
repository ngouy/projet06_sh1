/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 15:00:24 by ngouy             #+#    #+#             */
/*   Updated: 2014/11/25 17:02:54 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	str1 = (char *)s1;
	str2 = (char *)s2;
	return (strncmp(str1, str2, n));
}
