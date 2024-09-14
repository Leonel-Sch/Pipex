/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:40:51 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/14 15:54:40 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*aloc;

	if (nmemb * size > 2147483647)
		return (NULL);
	aloc = (char *)malloc(sizeof(char) * (size * nmemb));
	if (!aloc)
		return (NULL);
	ft_bzero(aloc, size * nmemb);
	return (aloc);
}
