/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:20:33 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/07 13:22:56 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_a(list **stack_a, int print)
{
    if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    *stack_a = (*stack_a)->prev;
    if (print == 1)
        printf("rra");
}

void reverse_b(list **stack_b, int print)
{
    if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    *stack_b = (*stack_b)->prev;
    if (print == 1)
        printf("rrb");
}

void reverse_anb(list **stack_a, list **stack_b, int print)
{
    if ((stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL ) &&\
    (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL))
        return ;
    reverse_a(stack_a, 0);
    reverse_b(stack_a, 0);
    if (print == 1)
        printf("rrr");
}
