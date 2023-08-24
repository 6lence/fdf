/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_triple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescobar <mescobar@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:58:01 by mescobar          #+#    #+#             */
/*   Updated: 2023/08/15 11:01:13 by mescobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdf.h"

static size_t	ft_words(char const *str, char c)
{
	size_t	count;
	size_t	index;

	if (!str || !str[0])
		return (0);
	count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == c)
			index++;
		else
		{
			count++;
			while (str[index] && str[index] != c)
				index++;
		}
	}
	return (count);
}

static size_t	ft_len(size_t i, char const *str, char c)
{
	size_t	count;

	count = 0;
	while (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static size_t	ft_position(size_t nb, const char *str, char c)
{
	while (str[nb] && str[nb] == c)
		nb++;
	return (nb);
}

int	ft_eny(const char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_split_new(int l, char ***tab, char const **s, char c)
{
	size_t	word_len;
	size_t	k;
	size_t	i;

	if (!s[l])
		exit(EXIT_FAILURE);
	tab[l] = malloc(sizeof(char *) * (ft_words(s[l], c) + 1));
	if (!tab)
		exit(EXIT_FAILURE);
	i = ft_position(0, s[l], c);
	k = 0;
	while (k < ft_words(s[l], c))
	{
		word_len = ft_len(i, s[l], c);
		tab[l][k] = ft_substr(s[l], i, word_len);
		i = ft_position(i + word_len, s[l], c);
		k++;
	}
	tab[l][k] = NULL;
	l++;
	return (l);
}
