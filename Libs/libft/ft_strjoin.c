/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:49:04 by ngouy             #+#    #+#             */
/*   Updated: 2014/11/13 12:00:18 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*rett;

	if (!s1 || !s2)
		return (NULL);
	if (s1[0] == s2[0] && s2[0] == '\0')
	{
		rett = (char *)malloc(1);
		rett[0] = '\0';
		return (rett);
	}
	i = 0;
	j = i;
	rett = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!rett)
		return (NULL);
	while (s1[i])
		rett[j++] = s1[i++];
	i = 0;
	while (s2[i])
		rett[j++] = s2[i++];
	return (rett);
}
