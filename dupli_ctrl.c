/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupli_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:12:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/18 21:38:14 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int dupli_chk(int argc, int *arry_of_ints)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (arry_of_ints[i] == arry_of_ints[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int dupli_ctrl(int argc, int *arry_of_ints)
{
	int		dupli_chk_res;

	dupli_chk_res = dupli_chk(argc, arry_of_ints);
	if (!dupli_chk_res)
	{
		free(arry_of_ints);
		return (0);
	}
	return (1);
}

