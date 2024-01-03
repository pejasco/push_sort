/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupli_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:12:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/03 18:54:03 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dupli_chk(int *arry_of_ints)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = int_arry_count(arry_of_ints);
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (arr_of_int[i] == arr_of_int[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int dupli_ctrl(int *arry_of_ints)
{
	int		dupli_chk_res;

	dupli_chk_res = dupli_chk(arry_of_ints);
	if (!dupli_chk_res)
	{
		free(arry_of_ints);
		return (0);
	}
	return (1);
}

