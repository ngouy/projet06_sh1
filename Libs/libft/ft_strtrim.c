/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:57:54 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/24 11:02:27 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	ret = ft_strnew(ft_strlen(s));
	if (!ret)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == (int)ft_strlen(s))
		return (ret);
	while (s[i])
	{
		ret[j] = s[i];
		j++;
		i++;
	}
	j--;
	while (ret[j] == ' ' || ret[j] == '\n' || ret[j] == '\t')
		ret[j--] = '\0';
	return (ret);
}
