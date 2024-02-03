/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:58 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 00:53:49 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_stack_a(t_list **ptr_to_stack, int *arry_of_ints)
{
	int		i;
	t_list	*tail;

	i = 1;
	if (arry_of_ints == NULL)
		return (NULL);
	tail = NULL;
	tail = append(tail, arry_of_ints[i], 0);
	*ptr_to_stack = tail;
	i++;
	while (i < arry_of_ints[0])
	{
		tail = append(tail, arry_of_ints[i], 0);
		i++;
	}
	free(arry_of_ints);
	arry_of_ints = NULL;
	return (tail);
}