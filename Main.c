/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:56:20 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/11 16:09:20 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **env)
{
	int i;
	i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;		
	}
	return 0;
}