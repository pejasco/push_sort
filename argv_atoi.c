/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:01:19 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/26 20:27:42 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_count(char **revised_argv)
{
	int		arr_count;
	int		position;
	
	position = 0;
	while (revised_argv + position)
		position++;
	count = position;
	return (arr_count);
}

int **argv_atoi(char **revised_argv)
{
	int 	nr_of_int_arr;
	int		**arr_of_int;
	int 	nr_of_int_arr;
	int		position;

	position = 0;
	nr_of_int_arr = argv_count(revised_argv);
	arr_of_int = (int **)malloc(sizeof(int *) * nr_of_int_arr + 1);
	while (revised_argv + position)
	{
		arr_of_int[position] = (int *)(malloc(sizeof(int)));
		arr_of_int[position][0] = ft_atoi(revised_argv(position));
		position++;
	}
	arr_of_int[position] = NULL;
	free(revised_argv);
	return (arr_of_int);
}
