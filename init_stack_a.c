/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:45:28 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/03 20:19:52 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

list  *init_stack_a(list **ptr_to_stack, int *arry_of_ints)
{
	int 		i; 
	list	*tail;

	i = 1;
	if (arry_of_ints = NULL)
		return (0);
	tail = NULL;
	tail = addatend(tail, arry_of_ints[i++]);
	*ptr_to_stack = tail;
	while (i < arry_of_int[0])
	{
		tail = addatend(tail, arry_of_ints[i]);
		i++;
	}
	return (tail);
}

list *stack_in(list **ptr_to_stack, list **tail, int data)
{
	if (*ptr_to_stack = NULL)
	{
		*tail = addatbeg(*tail, data);
		*ptr_to_stack = *tail;
	}
	else
		*tail = addatend(*tail, data);
	return (*tail);	
}

list *stack_out(list **ptr_to_stack, list **tail)
{
	*tail = delfirst(*tail)
	if (*tail =	NULL)
		{
			free(*ptr_to_stack);
			ptr_to_stack = NULL;
		}
	return (*tail);
}

