/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:27:16 by ngouy             #+#    #+#             */
/*   Updated: 2014/11/13 11:44:57 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		k;
	int		j;

	if (s1[0] == s2[0] && s1[0] == '\0')
		return ((char *)s1);
	i = 0;
	j = ft_strlen(s2);
	while (s1[i])
	{
		k = 0;
		while (s1[i + k] == s2[k])
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
