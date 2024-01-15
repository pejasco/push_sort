/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:19:29 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/15 23:19:45 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3_algo_rev(list **stack, list **fir_node, list **sec_node, list **thi_node)
{
    //2>1>3
    if (((*thi_node)->rank > (*fir_node)->rank)
            && (*fir_node)->rank > (*sec_node)->rank)
        reverse_b(stack, 1);
    //1>2>3
    else if (((*thi_node)->rank > (*sec_node)->rank)
            && (*sec_node)->rank > (*fir_node)->rank)
    {
        swap_b(stack, 1);
        reverse_b(stack, 1);
    }
    //3>1>2
    else if (((*fir_node)->rank > (*thi_node)->rank)
            && (*thi_node)->rank > (*sec_node)->rank)
    {
        reverse_b(stack, 1);
        swap_b(stack, 1);
    }
    //1>3>2
    else if (((*sec_node)->rank > (*thi_node)->rank)
            && (*thi_node)->rank > (*fir_node)->rank)
        rotate_b(stack, 1);
    //2>3>1
    else if (((*sec_node)->rank > (*fir_node)->rank)
            && (*fir_node)->rank > (*thi_node)->rank)
        swap_b(stack, 1);
    else
        return ;
}

int sort_2_rev(list **stack)
{
    int     exist_res;

    exist_res = rank_exist(stack);
    sort_2_rank(stack, exist_res);
    if((*stack)->rank < (*stack)->next->rank)
        swap_b(stack, 1);
}



int sort_3_rev(list **stack)
{
    list    *fir_node;
    list    *sec_node;
    list    *thi_node;
    int     exist_res;

    exist_res = rank_exist(stack);
    sort_3_rank(stack, exist_res);
    fir_node = *stack; 
    sec_node = (*stack)->next;
    thi_node = (*stack)->next->next;
    sort_3_algo_rev(stack, &fir_node, &sec_node, &thi_node);
}

void auto_push_a(list **stack_a, list **stack_b, int no_of_time, int print)
{
    int     i;

    i = 0;
    while (i < no_of_time)
    {
        push_a(stack_a, stack_b, 1);
    }
    i++;
}

void auto_push_b(list **stack_a, list **stack_b, int no_of_time, int print)
{
    int     i;

    i = 0;
    while (i < no_of_time)
    {
        push_b(stack_a, stack_b, 1);
    }
    i++;
}


int small_sort_rev(list **stack_a, list **stack_b)
{
    int     count;

    count = count_in_stack(stack_b);
    printf("count----->%d\n", count);
    if (count <= 0 || count > 3)
        return ;
    if (count == 1)
    {
        push_a(stack_a, stack_b, 1);
        return (1);
    }
    if (count == 2)
    {
        sort_2_rev(stack_b);
        auto_push_a(stack_a, stack_b, 2, 1);
        return (2);
    }
    if (count == 3)
    {
        sort_3_rev(stack_b);
        autp_push_a(stack_a, stack_b, 3, 1);
        return (3);
    }
}