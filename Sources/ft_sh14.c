/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh14.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:35:28 by ngouy             #+#    #+#             */
/*   Updated: 2015/04/03 16:34:54 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/ft_minishell1.h"

int					ft_test_arg0(char *arg0)
{
	if (!ft_strcmp(arg0, "cd"))
		return (1);
	if (!ft_strcmp(arg0, "exit"))
		return (2);
	if (!ft_strcmp(arg0, "setenv"))
		return (3);
	if (!ft_strcmp(arg0, "unsetenv"))
		return (4);
	if (!ft_strcmp(arg0, "env"))
		return (5);
	return (0);
}

static int			ft_check_exit(char **envp, char **args, int argc)
{
	int		ret;

	ret = 0;
	if (args[1])
		ret = ft_atoi(args[1]);
	(void)envp;
	(void)argc;
	return (ret);
}

static int			ft_knew_cmd(char **args, char **envp, int argc)
{
	int		arg0;

	if ((arg0 = ft_test_arg0(args[0])) != 0)
	{
		if (arg0 == 1)
			return (ft_check_cd(envp, args, argc));
		if (arg0 == 2)
			return (ft_check_exit(envp, args, argc));
		if (arg0 == 3)
			return (ft_check_setenv(envp, args, argc));
		if (arg0 == 4)
			return (ft_check_unsetenv(envp, args, argc));
		if (arg0 == 5)
			return (ft_check_env(envp, args, argc));
	}
	return (-10);
}

int					ft_ttaux(int argc, char **argv, char **env)
{
	char		**path;
	char		*name;
	t_s			s;

	s.j = 0;
	name = argv[0];
	s.i = 0;
	if (!ft_found(env, "PATH=", 1))
		(SB(name, argv, env) == -1) ? ft_printff(P1, NULL, 0) : 0;
	else
	{
		path = ft_strsplit(ft_found(env, "PATH=", 1), ':');
		while ((s.ind = ft_sub_syscall(name, argv, env) == -1) && path[s.i])
		{
			s.j = access(name, F_OK) && s.ind == -1 ? s.j++ : s.j;
			name = ft_fr(ft_strjoin(path[s.i], "/"), name, s.i);
			name = ft_fr(ft_strjoin(name, argv[0]), name, 1);
			s.i++;
		}
		if (!path[s.i] && ft_printff("sh1:", GG(argv[0], s.j), 0))
			ft_putendl(argv[0]);
		ft_free_tab(path);
		s.i ? free(name) : (void)s.i;
	}
	return (argc - argc);
}

int					tt(int argc, char **argv, char **env)
{
	int			ret;
	char		**temp;
	int			cpt;
	char		*tp;

	cpt = 0;
	ret = 0;
	temp = argv;
	if (argc == 0)
		return (0);
	while (temp && temp[cpt] && temp[cpt][0])
	{
		if (temp[cpt][0] == '~' && ft_found(env, "HOME=", 0))
		{
			if (ft_found(env, "HOME=", 0) && (tp = ft_strjoin(ft_found(env,
							"HOME=", 1), temp[cpt] + 1)))
				temp[cpt] = ft_fr(tp, temp[cpt], 1);
		}
		else if (temp[cpt][0] == '~')
			return (ft_printff("cd : unable to found HOME\n", NULL, 0));
		cpt++;
	}
	return ((ft_knew_cmd(argv, env, argc)
	!= -10) ? 1 : (ft_ttaux(argc, argv, env)));
}
