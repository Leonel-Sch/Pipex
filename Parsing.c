/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:56:14 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/11 20:09:46 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	ft_parsing(char *cmd1, char *cmd2, char **env)
{
	int i;
	int j;
	char *path;
	char **mpath;

	i = 0;
	j = 0;
	mpath = NULL;
	if (ft_strchr(cmd1, '/') == NULL)
	{
		while(env[i])
		{
			if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H')
			{
				path = env[i];
				break;
			}
			i++;
		}
	}
	else
	{
		printf("prout\n");
	}
	if (ft_strchr(cmd2, '/') == NULL)
	{
		while(env[i])
		{
			if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H')
			{
				path = env[i];
				break;
			}
			i++;
		}
	}
	else
	{
		printf("prout\n");
	}
	i = 0;
	mpath = ft_split(path, ':');
	while (mpath[i] != NULL)
	{
		printf("%s\n", mpath[i]);
		i++;
	}
}