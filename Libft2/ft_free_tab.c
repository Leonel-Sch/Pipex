/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:15:12 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/14 15:56:02 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_tab(char **tab, int i)
{
	int	j;

	j = 0;
	i++;
	while (tab[j] != NULL)
	{
		free(tab[j]);
		tab[j] = NULL;
		j++;
	}
	free(tab);
	return (NULL);
}
