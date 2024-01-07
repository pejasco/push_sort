/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:05:57 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/06 19:24:05 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(list **stack_a)
{
	list 	*temp;
	int		aux;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	temp = (*stack_a);
	if (temp == NULL || temp->next == temp)
		return ;
	aux = temp->data;
	temp->data = temp->next->data;
	temp->next->data = aux;
}

void swap_b(list **stack_b)
{
	list 	*temp;
	int		aux;

	if (stack_b == NULL || *stack_b == NULL)
		return;
	temp = (*stack_b);
	if (temp == NULL || temp->next == temp)
		return ;
	aux = temp->data;
	temp->data = temp->next->data;
	temp->next->data = aux;
}

void swap_anb(list **stack_a, list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
        return;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return;
	swap_a(stack_a);
	swap_b(stack_b);
}
