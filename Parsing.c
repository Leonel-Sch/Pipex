/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:56:14 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/12 19:52:35 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	ft_clean_path(char **mpath)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(mpath[0]) - 5;
	while (i < j)
	{
		mpath[0][i] = mpath[0][i + 5];
		i++;
	}
}
void	ft_clean_args(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (pipex->cmd1args != NULL)
	{
		while (pipex->cmd1args[i] != ' ')
			i++;
		while (pipex->cmd1args[i])
			pipex->cmd1args[j++] = pipex->cmd1args[i++];
		pipex->cmd1args[j] = '\0';
	}
	i = 0;
	j = 0;
	if (pipex->cmd2args != NULL)
	{
		while (pipex->cmd2args[i] != ' ')
			i++;
		while (pipex->cmd2args[i])
			pipex->cmd2args[j++] = pipex->cmd2args[i++];
		pipex->cmd2args[j] = '\0';
	}
	pipex->tabarg1 = ft_split(pipex->cmd1args, ' ');
	pipex->tabarg2 = ft_split(pipex->cmd2args, ' ');
}

void	ft_isolate_cmd_args(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (ft_strchr(pipex->cmd1, ' '))
	{
		pipex->cmd1args = ft_strdup(pipex->cmd1);
		while (pipex->cmd1[i] != ' ')
			i++;
		while (pipex->cmd1[i])
			pipex->cmd1[i++] = '\0';
	}
	i = 0;
	if (ft_strchr(pipex->cmd2, ' '))
	{
		pipex->cmd2args = ft_strdup(pipex->cmd2);
		while (pipex->cmd2[i] != ' ')
			i++;
		while (pipex->cmd2[i])
			pipex->cmd2[i++] = '\0';
	}
	ft_clean_args(pipex);
}

void	ft_check_access(t_pipex *pipex, char **mpath)
{
	char	*cache;
	char	*cache2;
	char	*path;
	int		i;

	i = 0;
	ft_isolate_cmd_args(pipex);
	while (i < 11)
	{
		path = ft_strjoin(mpath[i], "/");
		cache = ft_strjoin(path, pipex->cmd1);
		cache2 = ft_strjoin(path, pipex->cmd2);
		i++;
		free(path);
		if (access(cache, X_OK) != 0)
			free(cache);
		else
			pipex->cmd1 = cache;
		if (access(cache2, X_OK) != 0)
			free(cache2);
		else
			pipex->cmd2 = cache2;
	}
	return ;
}

char	**ft_path(char **env)
{
	char	*path;
	char	**mpath;
	int		i;
	int		j;

	path = NULL;
	mpath = NULL;
	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
			&& env[i][3] == 'H')
		{
			path = env[i];
			break ;
		}
		i++;
	}
	mpath = ft_split(path, ':');
	ft_clean_path(mpath);
	return (mpath);
}

void	ft_parsing(t_pipex *pipex, char **env)
{
	char	**mpath;

	mpath = ft_path(env);
	ft_check_access(pipex, mpath);
	ft_free_tab(mpath, 0);
}
