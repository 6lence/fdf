/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:26:31 by mescobar          #+#    #+#             */
/*   Updated: 2023/02/06 16:09:59 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c < 58 && c > 47) || (c < 123 && c > 96)
		|| (c < 91 && c > 64))
		return (1);
	return (0);
}