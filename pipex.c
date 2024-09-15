/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:34:57 by leonel            #+#    #+#             */
/*   Updated: 2024/09/15 12:49:29 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	ft_execution(t_pipex *pipex)
{
	int fd[2];
	pid_t pid;
	pid_t pid2;
	//int out;
	
	//out = open(pipex->outfile, )
	if (pipe(fd) == -1)
	{
		ft_printf("ECHEC");
	}

	pid = fork();
	if (pid == -1)
	{
		ft_printf("ECHEC");
	}

	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execve(pipex->cmd1, pipex->tabarg1, NULL);
		close(fd[1]);
	}
	
	pid2 = fork();
	if (pid2 == -1)
	{
		ft_printf("ECHEC");
	}

	if (pid2 == 0)
	{
		close(fd[1]);
		//dup2(fd[0], STDOUT_FILENO);
		execve(pipex->cmd2, pipex->tabarg2, NULL);
		close(fd[0]);
	}
}
