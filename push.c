/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:20:03 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/06 20:16:53 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(list **stack_a, list **stack_b)
{
	list *tail_of_a;
	list *tail_of_b;
	int nbr;

	if (stack_a == NULL)
		return ;
	nbr = (*stack_a)->data;
	tail_of_a = tail_find(stack_a);
	tail_of_b = tail_find(stack_b);
	tail_of_a = pop(tail_of_a);
	if (tail_of_a == NULL)
		*stack_a = NULL;
	*stack_a = tail_of_a->next;
	tail_of_b = push(tail_of_b, nbr);
	*stack_b = tail_of_b->next;
}
