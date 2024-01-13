/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:01:25 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/13 01:05:21 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     sorted(list **stack, char order)
{
    list    *current;
    int     i;

    i = 0;
    current = *stack;
    if (order == 'a' || order == 'A')
    {
        while (i < count_in_stack(stack))
        {
            if (current->data >= current->next->data)
                return (1);
            i++;
        }
    }
    if (order == 'd' || order == 'D')
    {
        while (i < count_in_stack(stack))
        {
            if (current->data <= current->next->data)
                return (1);
            i++;
        }
    }
    return (0);
}

void    stack_b_sort(list **stack)
{
    int     sort_or_not;
    int     count;

    sort_or_not = sorted(stack, 'a');
    while (count >= 4 || sorted)
    {
        

    }
    return ;
}