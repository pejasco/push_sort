/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:20:33 by chuleung          #+#    #+#             */
/*   Updated: 2024/02/03 00:28:01 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_list **stack_a, int print)
{
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	*stack_a = (*stack_a)->prev;
	if (print == 1)
		write(1, "rra\n", 4);
}

void	reverse_b(t_list **stack_b, int print)
{
	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	*stack_b = (*stack_b)->prev;
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	reverse_anb(t_list **stack_a, t_list **stack_b, int print)
{
	if ((stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL ) && \
		(stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL))
		return ;
	reverse_a(stack_a, 0);
	reverse_b(stack_a, 0);
	if (print == 1)
		write(1, "rrr\n", 4);
}
