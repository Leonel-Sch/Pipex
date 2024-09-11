/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:56:20 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/11 20:01:34 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	int i;
	i = 0;
	if (argc < 2)
	{
		return (0);
	}
	ft_parsing(argv[2], argv[3], env);
	return 0;
}