/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:34:56 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/27 13:14:54 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/ft_minishell1.h"

static int			ft_final_cd(char **envp, char **args, int argc)
{
	char		*temp1;
	char		*temp2;

	temp2 = ft_found(envp, "PWD=", 1);
	if (!temp2)
		return (ft_printff("sh1 : unable to found PWD\n", NULL, 0) - 20);
	temp1 = ft_found(envp, "OLDPWD=", 1);
	if (!temp1)
	{
		temp2 = ft_strncpy(temp2, args[1], ft_strlen(args[1]) + 1);
		return (0);
	}
	temp1 = ft_strncpy(temp1, temp2, ft_strlen(temp2) + 1);
	chdir(args[1]);
	getcwd(temp2, LEN - 20);
	(void)argc;
	return (0);
}

int					ft_check_cd_aux1(char **envp, char **args, int argc)
{
	int			ret;
	struct stat	stats;

	ret = 0;
	ret = stat(args[1], &stats);
	if (ret == -1)
		return (ft_printff("cd : no such file or directory: ", args[1], 1));
	if (!(S_IFDIR & stats.st_mode))
		return (ft_printff("cd : not a directory: ", (args[1]), 1));
	if (!(S_IXUSR & stats.st_mode))
		return (ft_printff("cd : permission denied: ", args[1], 1) - 22);
	return (ft_final_cd(envp, args, argc));
}

int					ft_check_cd(char **envp, char **args, int argc)
{
	char		*pwd;
	char		*oldpwd;
	char		*home;

	if (argc == 1)
	{
		oldpwd = (ft_found(envp, "OLDPWD=", 1));
		pwd = ft_found(envp, "PWD=", 1);
		if (!(home = ft_found(envp, "HOME=", 1)))
			return (ft_printff("cd : unable to found HOME\n", NULL, 0));
		if (!opendir(home))
			return (ft_printff("cd : no such file or directory: ", home, 1));
		if (oldpwd && pwd)
			oldpwd = ft_strncpy(oldpwd, pwd, ft_strlen(pwd) + 1);
		if (!home)
			return (0);
		if (pwd)
			pwd = ft_strncpy(pwd, home, ft_strlen(home) + 1);
		return (chdir(home) + 1);
	}
	if (argc > 2)
		return (ft_printff("cd : too many arguments\n", NULL, 0) - 23);
	else if (ft_check_cd_aux2(envp, args, argc))
		return (1);
	return (ft_check_cd_aux1(envp, args, argc));
}

int					ft_check_setenv(char **envp, char **args, int argc)
{
	char	*tmp;
	int		cpt;
	char	*ff;

	cpt = 0;
	if (argc == 1 || !ft_strchr(args[1] + 1, '=') || args[1][0] == '=')
	{
		(argc == 1) ? ft_put_env(envp) :
			(void)ft_printff("usage: setenv [var=[value]]\n", NULL, 0);
		return (0);
	}
	ff = ft_strsub(args[1], 0, L(args[1]) - L(ft_strchr(args[1], '=')));
	if ((tmp = ft_found(envp, ff, 1)))
		ft_strncpy(tmp, ft_strchr(args[1], '='), ft_strlen(args[1]) + 1);
	else
	{
		while (envp[cpt] && envp[cpt][0])
			cpt++;
		if (cpt != NB)
			envp[cpt] = ft_strncpy(envp[cpt], args[1], ft_strlen(args[1]) + 2);
		(cpt == NB && argc == 2) ? ft_printff(P2, NULL, 0) : 3;
	}
	(argc >= 3) ? ft_check_setenv(envp, args + 1, argc - 1) : 1;
	free(ff);
	return (0);
}

int					ft_check_unsetenv(char **envp, char **args, int argc)
{
	char		*temp;

	if (argc == 1)
		return (ft_printff("usage: unsetenv [var]\n", NULL, 0) - 23);
	else if ((temp = ft_found(envp, args[1], 0)) && !ft_strchr(args[1], '='))
	{
		temp[0] = 0;
		if (argc >= 3)
			ft_check_unsetenv(envp, args + 1, argc - 1);
	}
	else
		ft_printff("unsetenv: variable is not set: ", args[1], 1);
	return (0);
}
