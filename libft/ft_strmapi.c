/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:42:06 by rmontgom          #+#    #+#             */
/*   Updated: 2021/10/31 23:54:14 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	k;
	char			*str;

	if (s == 0 || *f == 0)
		return (NULL);
	k = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (k + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < k)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
