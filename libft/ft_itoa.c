/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:28:15 by rmontgom          #+#    #+#             */
/*   Updated: 2021/11/02 13:59:37 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_znak(int n)
{
	int	znak;

	znak = 1;
	if (n < 0)
		znak = -1;
	return (znak);
}

char	*ft_itoa(int n)
{
	int		len;
	int		znak;
	char	*str;

	znak = ft_znak(n);
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = (char)((n % 10) * ((2 * (n > 0)) - 1) + '0');
		n /= 10;
	}
	if (znak < 0)
		str[--len] = '-';
	return (str);
}
