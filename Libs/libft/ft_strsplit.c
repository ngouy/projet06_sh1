/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:05:46 by ngouy             #+#    #+#             */
/*   Updated: 2015/03/04 16:47:25 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_nbofwords(char const *s, char c)
{
	int		ret;
	int		i;

	i = 0;
	ret = i;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			if (i == 0 || s[i - 1] == c)
				ret++;
		}
		i++;
	}
	return (ret);
}

static size_t		ft_wordsize(char const *s, int i, char c)
{
	size_t		ret;

	ret = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		ret++;
	}
	return (ret);
}

static char			**ft_empt(void)
{
	char	**ret;

	ret = (char **)malloc(sizeof(char *) * 1 + 1);
	ret[0] = (char *)malloc(sizeof(char));
	ret[0] = NULL;
	ret[1] = NULL;
	return (ret);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**ret;
	int			i;
	int			j;
	size_t		size_ret;

	if (!s)
		return (NULL);
	i = 0;
	j = i;
	size_ret = ft_nbofwords(s, c);
	if (size_ret == 0)
		return (ft_empt());
	ret = (char **)malloc(sizeof(char *) * size_ret + 1);
	if (!ret)
		return (NULL);
	ret[size_ret] = NULL;
	while (j < (int)size_ret)
	{
		while (s[i] == c)
			i++;
		ret[j] = ft_strsub(s, i, ft_wordsize(s, i, c));
		i = i + ft_wordsize(s, i, c);
		j++;
	}
	return (ret);
}
