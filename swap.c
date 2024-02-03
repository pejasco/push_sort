/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:05:57 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 00:22:00 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_list **stack_a, int print)
{
	t_list 	*temp;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	temp = (*stack_a);
	if (temp == NULL || temp->next == temp)
		return ;
	temp = *stack_a;
	temp->prev->next = temp->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = temp->prev;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->prev = (*stack_a);
	if (print == 1)
		write(1, "sa\n", 3);
}

void swap_b(t_list **stack_b, int print)
{
	t_list 	*temp;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	temp = (*stack_b);
	if (temp == NULL || temp->next == temp)
		return ;
	temp = *stack_b;
	temp->prev->next = temp->next;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = temp->prev;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	temp->prev = (*stack_b);
	if (print == 1)
		write(1, "sb\n", 3);
}

void swap_anb(t_list **stack_a, t_list **stack_b, int print)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return;
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return;
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (print == 1)
		write(1, "ss\n", 3);
}