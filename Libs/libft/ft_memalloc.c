/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:29:00 by ngouy             #+#    #+#             */
/*   Updated: 2015/02/24 10:56:37 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*ret;
	char	*tb;
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	ret = malloc(sizeof(char) * size);
	tb = (char *)ret;
	if (!ret)
		return (NULL);
	while (i < size)
	{
		tb[i] = '\0';
		i++;
	}
	return (ret);
}
