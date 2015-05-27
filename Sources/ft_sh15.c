/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:35:36 by ngouy             #+#    #+#             */
/*   Updated: 2015/04/03 11:15:35 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/ft_minishell1.h"

int					ft_argc(char **tab)
{
	int	ret;

	ret = 0;
	while (tab[ret])
		ret++;
	return (ret);
}

void				ft_switch_tab(char **line)
{
	char		*temp;

	temp = *line;
	while (*temp)
	{
		*temp = *temp == '\t' ? ' ' : *temp;
		temp++;
	}
}

void				ft_free_tab(char **t)
{
	int		i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

static void			ft_ctrlz(int i)
{
	(void)i;
	write(1, "\b\b  \b\b", 6);
}

char				**ft_st(char **envp)
{
	signal(2, ft_ctrlc);
	signal(3, ft_ctrlz);
	ft_prompt(getcwd(g_pwd, 1000));
	return (ft_set_env(envp));
}
