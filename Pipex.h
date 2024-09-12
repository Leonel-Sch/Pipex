/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:56:41 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/12 19:50:59 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft2/libft.h"
# include <unistd.h>
# include <wait.h>

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd1args;
	char	**tabarg1;
	char	*cmd2;
	char	*cmd2args;
	char	**tabarg2;
}			t_pipex;

void		ft_parsing(t_pipex *pipex, char **env);

#endif