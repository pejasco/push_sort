/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:19:51 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/07 13:21:00 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(list **stack_a)
{
    if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    *stack_a = (*stack_a)->next;
}

void rotate_b(list **stack_b)
{
    if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    *stack_b = (*stack_b)->next;
}

void rotate_anb(list **stack_a, list **stack_b)
{
    if ((stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL ) &&\
    (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL))
        return ;
    rotate_a(stack_a);
    rotate_b(stack_b);
}