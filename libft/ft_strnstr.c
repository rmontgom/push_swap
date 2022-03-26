/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:30:51 by rmontgom          #+#    #+#             */
/*   Updated: 2021/11/03 17:48:03 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == needle[0])
		{
			while (needle[j] != '\0' && big[i + j] == needle[j]
				&& i + j < len)
			{
				if (needle[j + 1] == '\0')
					return ((char *)&big[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
