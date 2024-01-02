/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:01:19 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/29 21:07:55 by chuleung         ###   ########.fr       */
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
	int		**arry_of_ints;
	int 	total_nr_of_int_arr;
	int		position;

	position = 0;
	nr_of_int_arr = argv_count(revised_argv);
	arr_of_int = (int **)malloc(sizeof(int *) * total_nr_of_int_arr + 1);
	while (revised_argv[position])
	{
		arr_of_int[position] = (int *)(malloc(sizeof(int)) + 1);
		arr_of_int[position][0] = ft_atoi(revised_argv[position]);
		arr_of_int[position][1] = '\0';
		position++;
	}
	arr_of_int[position] = NULL;
	free(revised_argv);
	return (arry_of_ints);
}

int atoi_limit_chk_sign(char *revised_argv)
{
	int	1st_element;
	int	sign;

	sign = 1;
	if (revised_argv[1st_element] == '-')
		sign = -1;
	return (sign)
}

int	atoi_limit_chk_algo(long projected_int_val, char *revised_argv, int sign)
{
	int		digit;

	while(*revised_argv)
	{		
		digit = *revised_argv - '0';
		if (sign > 0)
		{
			if (projected_int_val > (INT_MAX - digit) / 10)
				return (1);
			projected_int_val = projected_int_val * 10 + digit;
		}
		if (sign < 0)
		{
			if (projected_int_val < (INT_MIN + digit) / 10)
				return (-1);
			projected_int_val = projected_int_val * 10 - digit;
		}
		revised_argv++;
	}
	return (0);
}

int **atoi_for_limit_chk(char *revised_argv)
{
	int		element;
	int 	sign;
	int		chk_result;

	element = 0;
	sign = atoi_limit_chk_sign(&revised_argv[element])
	if (revised_argv[element] == '-')
		element++;
	chk_result = atoi_limit_chk_algo(0, &revised_argv[element], sign);
	if (!chk_result)
		return (1);
	return (0);		
}
