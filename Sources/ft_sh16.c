/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh16.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:35:47 by ngouy             #+#    #+#             */
/*   Updated: 2015/04/03 14:55:18 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/ft_minishell1.h"

int					ft_printff(char *a, char *b, int i)
{
	ft_putstr(a);
	if (b)
		ft_putstr(b);
	if (i)
		ft_putstr("\n");
	return (23);
}

static int			ft_auxmain(char *line, char **en)
{
	char	**args;

	g_ii = 1;
	ft_switch_tab(&line);
	args = ft_strsplit(line, ' ');
	if (!args[0])
		(void)args;
	else if (ft_test_arg0(args[0]) == 2)
	{
		if (ft_argc(args) <= 2)
			return (ft_argc(args) == 2 ? ft_atoi(args[1]) : 0);
		ft_printff("exit : too many arguments\n", NULL, 0);
	}
	else
		tt(ft_argc(args), args, en);
	if (args)
		ft_free_tab(args);
	ft_prompt(getcwd(g_pwd, 1000));
	return (-1);
}

void				ft_prompt(char *a)
{
	ft_putstr("\033[1;4;34mngouy_sh1\033[0m \033[36;1m:\033[0m ");
	ft_putstr(a);
	ft_putstr("\n            \033[1;31m>\033\033[32m>\033[0m ");
}

char				*ft_fr(char *s1, char *s2, int i)
{
	if (i != 0)
		free(s2);
	return (s1);
}

int					main(int argc, char **argv, char **envp)
{
	int		ind;
	char	*line;
	char	**en;
	int		ll;

	en = ft_st(envp);
	(void)argc;
	(void)argv;
	while (42)
	{
		g_ii = 0;
		ind = get_next_line(0, &line);
		if (!line || ind == 0)
			return (ft_printff("\n", NULL, 0) - 22);
		else if (line[0] == '\0')
			ft_prompt(getcwd(g_pwd, 1000));
		else
		{
			if ((ll = ft_auxmain(line, en)) != -1)
				return (ll);
		}
		if (ind && line)
			free(line);
	}
	return (0);
}
