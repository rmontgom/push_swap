/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmontgom <rmontgom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:59:33 by rmontgom          #+#    #+#             */
/*   Updated: 2022/03/26 17:20:23 by rmontgom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"

#include "./libft/libft.h"
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

int	duplicat(char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
			{
				free_pointer(arr);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// typedef struct s_list
// {
// 	int value;
// 	int index;
// }; t_list

void Error()
{
	write(2, "Error\n", 6);
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
	int *unsort;
	int k;
	int j;

	unsort = (int *)malloc(sizeof(int) * (get_size(argv)));
	if (!unsort)
		return (NULL);
	i = 1;
	while (argv[i])
	{
		buf = ft_split(argv[i], ' ');
		k = 0;
		j = 0;
		if (duplicat(buf) == 1)
			Error();
		else
		{
			while (buf[j])
			{
				unsort[k++] = ft_atoi(buf[j++]);
				printf("%d\n", unsort[k]);
			}
			free_pointer(buf);
			i++;
		}
	}
	return (unsort);
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
	printf("%d\n", p);
	pars_elements(argv);
	// while (i < p)
	// {
	// 	printf("%d\n", pars_elements(argv)[i]);
	// 	i++;
	// }
	// return (0);	
}