/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:22:29 by mescobar          #+#    #+#             */
/*   Updated: 2023/02/15 09:49:10 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pt;
	size_t	useless;

	useless = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (useless / size != nmemb || useless / nmemb != size)
		return (NULL);
	pt = malloc(useless);
	if (!pt)
		return (NULL);
	ft_bzero(pt, useless);
	return (pt);
}
