/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_in_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:58 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/16 12:55:40 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

list  *init_stack_a(list **ptr_to_stack, int *arry_of_ints)
{
	int 		i; 
	list	*tail;

	i = 1;
	if (arry_of_ints == NULL)
		return (NULL);
	tail = NULL;
	tail = append(tail, arry_of_ints[i]);
	*ptr_to_stack = tail;
	i++;
	while (i < arry_of_ints[0])
	{
		tail = append(tail, arry_of_ints[i]);
		i++;
	}
	free(arry_of_ints);
	arry_of_ints = NULL;
	return (tail);
}
/*
list *stack_in(list **ptr_to_stack, list **tail, int data)
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

list *stack_out(list **ptr_to_stack, list **tail)
{
	*tail = pop(*tail);
	if (*tail == NULL)
		*ptr_to_stack = NULL;
	return (*tail);
}
*/