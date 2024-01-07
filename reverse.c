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

void reverse_a(list **stack_a)
{
    if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    *stack_a = (*stack_a)->prev;    
}

void reverse_b(list **stack_b)
{
    if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    *stack_b = (*stack_b)->prev;    
}

void reverse_anb(list **stack_a, list **stack_b)
{
    if ((stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL ) &&\
    (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL))
        return ;
    reverse_a(stack_a);
    reverse_b(stack_a);
}
