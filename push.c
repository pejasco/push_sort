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

void push_a(list **stack_a, list **stack_b)
{
	list *tail_of_a;
	list *tail_of_b;
	int nbr;

	if (stack_b == NULL)
		return ;
	if ((*stack_b) == NULL)
		return ;
	else
		nbr = (*stack_b)->data;
	tail_of_a = tail_find(stack_a);
	tail_of_b = tail_find(stack_b);
	tail_of_b = pop(tail_of_b);
	if (tail_of_b == NULL)
		*stack_b = NULL;
	else
		*stack_b = tail_of_b->next;
	tail_of_a = push(tail_of_a, nbr);
	*stack_a = tail_of_a->next;
}

void push_b(list **stack_a, list **stack_b)
{
	list *tail_of_a;
	list *tail_of_b;
	int nbr;

	if (stack_a == NULL)
		return ;
	if ((*stack_a) == NULL)
		return ;
	else
		nbr = (*stack_a)->data;
	tail_of_a = tail_find(stack_a);
	tail_of_b = tail_find(stack_b);
	tail_of_a = pop(tail_of_a);
	if (tail_of_a == NULL)
		*stack_a = NULL;
	else
		*stack_a = tail_of_a->next;
	tail_of_b = push(tail_of_b, nbr);
	*stack_b = tail_of_b->next;
}

/*
	nbr = (*stack_a)->data;
	tail/Users/macbook/Desktop/projects _of_a = tail_find(stack_a);
	tail_of_b = tail_find(stack_b);
	test_a = tail_of_a->data;
	test_b = tail_of_b->data;
	printf("diuuuu %d", nbr);
	printf("diuuuu %d", test_a);
	printf("diuuuu %d", test_b);
*/

