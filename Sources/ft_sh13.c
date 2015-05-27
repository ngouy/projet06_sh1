/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh13.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:35:21 by ngouy             #+#    #+#             */
/*   Updated: 2015/04/03 17:56:18 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/ft_minishell1.h"

static int			ft_auxenv1(int *argc, int i, char **args, char **exec)
{
	if (i != *argc)
	{
		(*argc)--;
		(*exec) = ft_strdup(args[i]);
		ft_bzero(args[i], 1);
		return (2);
	}
	return (0);
}

static void			ft_env_final(char **envp, char **args, char **temp, int j)
{
	char		**path;
	char		*name;
	t_s			s;

	s.j = 0;
	name = args[j];
	s.i = 0;
	if (!ft_found(envp, "PATH=", 1) && (s.i = SB(name, args + j, temp)) == -1)
		ft_printff("sh1: PATH not found\n", NULL, 0);
	else if (s.i == 0)
	{
		path = ft_strsplit(ft_found(envp, "PATH=", 1), ':');
		while ((s.ind = SB(name, args + j, temp) == -1) && path[s.i])
		{
			s.j = access(name, F_OK) && s.ind == -1 ? s.j++ : s.j;
			name = ft_fr(ft_strjoin(path[s.i], "/"), name, s.i);
			name = ft_fr(ft_strjoin(name, args[j]), name, 1);
			s.i++;
		}
		if (!path[s.i] && ft_printff("sh1:", GG(args[j], s.j), 0))
			ft_putendl(args[j]);
		ft_free_tab(path);
	}
	ft_free_env(temp);
}

static int			ft_auxenv2(char **envp, char **args, char *exec, int i)
{
	(void)envp;
	args[i] = ft_strcpy(args[i], exec);
	free(exec);
	return (1);
}

static int			ft_fenv(char ***temp)
{
	ft_put_env(*temp);
	ft_free_env(*temp);
	return (0);
}

int					ft_check_env(char **envp, char **args, int argc)
{
	char		**temp;
	t_s			s;
	char		*exec;

	s.i = 1;
	s.j = 0;
	if (argc == 1)
		ft_put_env(envp);
	else
	{
		s.j = ft_tmp_env(&args, &argc, &temp, envp);
		if (s.j == 3)
			return (0);
		while (s.i < argc && ft_strchr(args[s.i] + 1, '='))
			s.i++;
		s.j = s.j + ft_auxenv1(&argc, s.i, args, &exec);
		(s.i != 1) ? ft_check_setenv(temp, args, argc) : 'l';
		if (s.j == 1)
			return (ft_fenv(&temp));
		argc = (s.j != 0) ? argc + ft_auxenv2(envp, args, exec, s.i) : argc;
		if (s.i == argc)
			return (ft_fenv(&temp));
		ft_env_final(envp, args, temp, s.i);
	}
	return (0);
}
