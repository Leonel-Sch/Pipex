/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:56:20 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/12 19:54:10 by lscheupl         ###   ########.fr       */
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
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc <= 2)
	{
		ft_printf("Not Enough Arguments\n");
		return (0);
	}
	ft_initialize_data(&pipex, argv);
	ft_parsing(&pipex, env);
	return (0);
}
