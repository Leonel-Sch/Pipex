/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:34:57 by leonel            #+#    #+#             */
/*   Updated: 2024/09/15 20:03:49 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"

int	ft_first_process(t_pipex *pipex, int *fd, pid_t pid)
{
	int infile_fd;
	
	infile_fd = open(pipex->infile, O_RDONLY);
	if (infile_fd == -1)
		return (ft_putstr_fd("Echec", 2), 1);
	if (pid == -1)
	{
		return (ft_putstr_fd("Echec", 2), 1);
	}	

	close(fd[0]);
	dup2(infile_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(infile_fd);
	execve(pipex->cmd1, pipex->tabarg1, NULL);
	return(0);
}

int	ft_second_process(t_pipex *pipex, int *fd)
{
	int outfile_fd;

	outfile_fd = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile_fd == -1)
		return (EXIT_FAILURE);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(fd[0]);
	close(outfile_fd);
	execve(pipex->cmd2, pipex->tabarg2, NULL);
	return (EXIT_FAILURE);
}

void	ft_execution(t_pipex *pipex)
{
	int fd[2];
	pid_t pid;
	pid_t pid2;
	int status;
	
	if (pipe(fd) == -1)
	{
		ft_printf("ECHEC");
		return ;
	}
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		ft_first_process(pipex, fd, pid);
	close(fd[1]);
	pid2 = fork();
	if (pid2 == -1)
		return ;
	if (pid2 == 0)
		ft_second_process(pipex, fd);
	close(fd[0]);
	waitpid(pid, &status, 0);
	waitpid(pid2, &status, 0);
	close(fd[0]);
	close(fd[1]);
}
//pid = fork();
	//if (pid == -1)
	//{
	//	ft_printf("ECHEC");
	//}
	

	//if (pid == 0)
	//{
	//	close(fd[0]);
	//	dup2(infile_fd, STDIN_FILENO);
	//	dup2(fd[1], STDOUT_FILENO);
	//	execve(pipex->cmd1, pipex->tabarg1, NULL);
	//	close(fd[1]);
	//}
	
	//pid2 = fork();
	//if (pid2 == -1)
	//{
	//	ft_printf("ECHEC");
	//}

	//if (pid2 == 0)
	//{
	//	close(fd[1]);
	//	dup2(fd[0], STDIN_FILENO);
	//	dup2(outfile_fd, STDOUT_FILENO);
	//	execve(pipex->cmd2, pipex->tabarg2, NULL);
	//	close(fd[0]);
	//}