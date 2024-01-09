/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utili.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:25:47 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/09 14:25:49 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_in_stack(list **stack)
{
    int count;
    list *current;

    if (*stack == NULL || stack == NULL)
        return (0);
    count = 0;
    current = *stack;
    while (current->next == current)
    {
        current = current->next;
        count++;
    }
    return (count);
}

int min_in_stack(list **stack)
{
    int min;
    list *current; 

    if (*stack == NULL || stack == NULL)
        return (0);
    current = *stack;
    min = (*stack)->data;
    while (current->next == (*stack))
    {
        if (current->data < min)
            min = current->data;
        current = current->next;
    }
    return (min);
}

list *copy_init_a(list **stack)
{
    list *stack_a;
    list *copy_of_a;
    list *tail_of_stack_a;
    list *tail_of_copy_a;

    if ((*stack) == NULL || stack == NULL)
        return (NULL);
    if ((*stack)->data)
        return (NULL);
    stack_a = *stack;
    tail_of_copy_a = append(tail_of_copy_a, stack_a->data);
    copy_of_a = tail_of_copy_a;
    tail_of_stack_a = stack_a->next;
    while (tail_of_stack_a != stack_a)
    {
        tail_of_copy_a = append(tail_of_copy_a, tail_of_stack_a->data);
        tail_of_stack_a = tail_of_stack_a->next;
    }
    return (copy_of_a);
}

int rank_in_stack(list **stack_or_chunk)
{
    list *



}