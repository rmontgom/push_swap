/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:59:33 by rmontgom          #+#    #+#             */
/*   Updated: 2022/03/26 03:44:00 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

#include "libft.h"
#include <stdio.h>

void	free_pointer(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	get_size(char **argv)
{
	int	size;
	int	i;
	int j;
	char	**buf;

	size = 0;
	i = 1;
	while (argv[i])
	{
		buf = ft_split(argv[i], ' ');
		j = 0;
		while (buf[j++])
			size++;
		free_pointer(buf);
		i++;
	}
	return (size);
}

int	*pars_elements(char **argv)
{
	int	i;
	char	**buf;
	int *numb;
	int k;
	int j;

	numb = (int *)malloc(sizeof(int) * (get_size(argv)));
	i = 1;
	while (argv[i])
	{
		buf = ft_split(argv[i], ' ');
		k = 0;
		j = 0;	
		while (buf[j])
		{
			numb[k] = ft_atoi(buf[j++]);
			// printf("%d\n", numb[k]);
			k++;
		}	
		// free_pointer(buf);
		i++;
	}
	return (numb);
}
// 	i = 1;
// 	*buf = (char *)malloc(sizeof(char) * argc)
// 	while (i < argc)
// 	{
// 		buf = ft_split(argv[i], ' ');
// 		i++;
// 	}
// }

int main(int argc, char **argv)
{
	int p;
	int *s;
	int i;
	
	p = get_size(argv);
	// printf("%d\n", p);
	s = pars_elements(argv);
	i = 0;
	while (i < p)
	{
		printf("%d\n", pars_elements(argv)[i]);
		i++;
	}
	return (0);	
}