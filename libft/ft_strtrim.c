/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:09:04 by rmontgom          #+#    #+#             */
/*   Updated: 2021/11/02 14:04:09 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

int	ft_stop(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL && i > 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		start;
	int		stop;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = ft_start(s1, set);
	stop = ft_stop(s1, set);
	if (start >= stop)
		return (ft_strdup(""));
	dst = (char *)malloc(sizeof(char) * (stop - start + 1 + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (start <= stop)
		dst[i++] = s1[start++];
	dst[i] = '\0';
	return (dst);
}
