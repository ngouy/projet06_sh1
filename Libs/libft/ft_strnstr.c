/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:54:14 by ngouy             #+#    #+#             */
/*   Updated: 2014/11/13 11:45:25 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		k;
	int		j;

	if (s1[0] == s2[0] && s1[0] == '\0')
		return ((char *)s1);
	i = 0;
	j = ft_strlen(s2);
	while (s1[i] && i < (int)n)
	{
		k = 0;
		while (s1[i + k] == s2[k] && i + k < (int)n)
		{
			if (s2[k] == '\0')
				return ((char *)s1 + i);
			k++;
		}
		if (k == j)
			return ((char *)s1 + i);
		else
			i++;
	}
	return (NULL);
}
