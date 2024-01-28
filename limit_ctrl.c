/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:01:19 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/28 15:12:37 by Scofield         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//the i has to be 1

int	atoi_limit_chk_sign(char *argv_sign)
{
	int	sign;

	sign = 1;
	if (*argv_sign == '-')
		sign = -1;
	return (sign);
}

int	atoi_limit_chk_algo(long projected_int_val, char *argv, int sign)
{
	int		digit;

	while (*argv)
	{
		digit = *argv - '0';
		if (sign > 0)
		{
			if (projected_int_val > (INT_MAX - digit) / 10)
				return (0);
			projected_int_val = projected_int_val * 10 + digit;
		}
		if (sign < 0)
		{
			if (projected_int_val < (INT_MIN + digit) / 10)
				return (0);
			projected_int_val = projected_int_val * 10 - digit;
		}
		argv++;
	}
	return (1);
}

int	atoi_for_limit_chk(char *argv)
{
	int		element;
	int		sign;
	int		chk_result;

	element = 0;
	sign = atoi_limit_chk_sign(&argv[element]);
	if (argv[element] == '-' || argv[element] == '+')
		element++;
	chk_result = atoi_limit_chk_algo(0, &argv[element], sign);
	if (!chk_result)
		return (0);
	return (1);
}

int	limit_chk(char **argv)
{
	int		i;
	int		atoi_for_limit_chk_res;

	i = 1;
	while (argv[i])
	{
		atoi_for_limit_chk_res = atoi_for_limit_chk(argv[i]);
		if (!atoi_for_limit_chk_res)
			return (0);
		i++;
	}
	return (1);
}

int	limit_ctrl(char **argv)
{
	int		limit_chk_res;

	limit_chk_res = limit_chk(argv);
	if (!limit_chk_res)
		return (0);
	return (1);
}

/*
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
*/
