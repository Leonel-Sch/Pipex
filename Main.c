/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:56:20 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/16 00:13:57 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"
#include <stdio.h>

void	ft_initialize_data(t_pipex *pipex, char **argv)
{
	pipex->cmd1 = NULL;
	pipex->cmd1 = NULL;
	if (argv[2] != NULL)
		pipex->cmd1 = argv[2];
	if (argv[3] != NULL)
		pipex->cmd2 = argv[3];
	pipex->cmd1args = NULL;
	pipex->cmd2args = NULL;
	pipex->infile = NULL;
	if (argv[1] != NULL)
		pipex->infile = argv[1];
	pipex->outfile = NULL;
	if (argv[4] != NULL)
		pipex->outfile = argv[4];
	pipex->tabarg1 = NULL;
	pipex->tabarg2 = NULL;
}

void	ft_print_everything(t_pipex *pipex)
{
	ft_printf("cmd 1 : %s\n", pipex->cmd1);
	int i = 0;
	ft_printf("ARGS 1 :");
	if (pipex->tabarg1 == NULL)
	{
		ft_printf(" NULL");
	}
	else
	{
		while (pipex->tabarg1[i])
		{
			ft_printf(" %s", pipex->tabarg1[i]);
			i++;
		}
	}
	ft_printf("\n");
	ft_printf("cmd 2 : %s\n", pipex->cmd2);
	ft_printf("ARGS 2 :");
	i = 0;
	if (pipex->tabarg2 == NULL)
	{
		ft_printf(" NULL");
	}
	else
	{
		while (pipex->tabarg2[i])
		{
			ft_printf(" %s", pipex->tabarg2[i]);
			i++;
		}
	}
	ft_printf("\n");
	ft_printf("infile : %s\n", pipex->infile);
	ft_printf("outfile : %s\n", pipex->outfile);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong Number of Arguments\n", 2);
		return (1);
	}
	ft_initialize_data(&pipex, argv);
	ft_parsing(&pipex, env);
	ft_print_everything(&pipex);
	ft_execution(&pipex);
	free(pipex.cmd1args);
	free(pipex.cmd2args);
	if (access(pipex.cmd1, X_OK) == 0)
		free(pipex.cmd1);
	if (access(pipex.cmd2, X_OK) == 0)
		free(pipex.cmd2);
	ft_free_tab(pipex.tabarg1, 0);
	ft_free_tab(pipex.tabarg2, 0);
	return (0);
}
