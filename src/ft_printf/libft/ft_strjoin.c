/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar42@student.42perpigna    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:29:53 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/26 21:01:41 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*chain;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	chain = ft_calloc(len, sizeof(char));
	if (!chain)
		return (NULL);
	i = 0;
	while (*s1)
		chain[i++] = *s1++;
	while (*s2)
		chain[i++] = *s2++;
	return (chain);
}
