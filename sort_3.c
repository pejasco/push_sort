/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:33:16 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/12 17:34:05 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3_algo(list **stack, list **fir_node, list **sec_node, list **thi_node)
{
    //2>1>3
    if (((*thi_node)->rank > (*fir_node)->rank)
            && (*fir_node)->rank > (*sec_node)->rank)
        swap_a(stack, 1);
    //3>2>1
    else if (((*fir_node)->rank > (*sec_node)->rank)
            && (*sec_node)->rank > (*thi_node)->rank)
    {
        rotate_a(stack, 1);
        swap_a(stack, 1);
    }
    //3>1>2
    else if (((*fir_node)->rank > (*thi_node)->rank)
            && (*thi_node)->rank > (*sec_node)->rank)
        rotate_a(stack, 1);
    //1>3>2
    else if (((*sec_node)->rank > (*thi_node)->rank)
            && (*thi_node)->rank > (*fir_node)->rank)
    {    
        swap_a(stack, 1);
        rotate_a(stack, 1);
    }
    //2>3>1
    else if (((*sec_node)->rank > (*fir_node)->rank)
            && (*fir_node)->rank > (*thi_node)->rank)
        reverse_a(stack, 1);
    else
        return ;
}

void sort_2_rank(list **stack)
{
    int     max;
    int     min;
    int     i;
    list    *current;

    i = 0;
    max = max_in_stack(stack);
    printf("max--->%d\n", max);
    min = min_in_stack(stack);
    printf("min--->%d\n", min);
    current = *stack;
    while (i < 2)
    {
        if (current->data == max)
            (current)->rank = 1;
        if (current->data == min)
            (current)->rank = 0;
        current = current->next;
        i++;
    }
}

void sort_3_rank(list **stack)
{
    int     max;
    int     min;
    int     i;
    list    *current;

    i = 0;
    max = max_in_stack(stack);
    printf("max--->%d\n", max);
    min = min_in_stack(stack);
    printf("min--->%d\n", min);
    current = *stack;
    while (i < 2)
    {
        if (current->data == max)
            (current)->rank = 2;
        else if (current->data == min)
            (current)->rank = 0;
        else
            (current)->rank = 1;
        current = current->next;
        i++;
    }
}

void sort_3(list **stack)
{
    int     count;
    list    *fir_node;
    list    *sec_node;
    list    *thi_node;


    count = count_in_stack(stack);
    printf("count----->%d\n", count);
    if (count <= 1 || count > 3)
        return ;
    
    if (count == 2)
    {
        sort_2_rank(stack);
        if((*stack)->rank > (*stack)->next->rank)
            swap_a(stack, 1);
    }
    if (count == 3)
    {
        sort_3_rank(stack);
        fir_node = *stack; 
        sec_node = (*stack)->next;
        thi_node = (*stack)->next->next;
        sort_3_algo(stack, &fir_node, &sec_node, &thi_node);
    }
}
