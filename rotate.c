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

void rotate_a(list **stack_a, int print)
{
    if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    *stack_a = (*stack_a)->next;
    if (print == 1)
        printf("ra\n");
}

void rotate_b(list **stack_b, int print)
{
    if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    *stack_b = (*stack_b)->next;
    if (print == 1)
        printf("rb\n");
}

void rotate_anb(list **stack_a, list **stack_b, int print)
{
    if ((stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL ) &&\
    (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL))
        return ;
    rotate_a(stack_a, 0);
    rotate_b(stack_b, 0);
    if (print == 1)
        printf("rr\n");
}