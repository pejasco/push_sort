/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:58 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/28 19:01:36 by Scofield         ###   ########.fr       */
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
/*
t_list *stack_in(t_list **ptr_to_stack, t_list **tail, int data)
{
	if (*ptr_to_stack == NULL)
	{
		*tail = push(*tail, data);
		*ptr_to_stack = *tail;
	}
	else
		*tail = append(*tail, data);
	return (*tail);	
}

t_list *stack_out(t_list **ptr_to_stack, t_list **tail)
{
	*tail = pop(*tail);
	if (*tail == NULL)
		*ptr_to_stack = NULL;
	return (*tail);
}
*/