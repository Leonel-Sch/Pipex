/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:34:57 by leonel            #+#    #+#             */
/*   Updated: 2024/09/14 18:49:33 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

void	ft_execution(t_pipex *pipex)
{
	int fd[2];
	pid_t pid;

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
	}
}
