/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:39:16 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/26 16:08:59 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_5_op_extend(t_stacks *stacks, t_list *node)
{
    int max;
    int min;
    int med;
    t_list *head;

    head = stacks->stack_a;
	max = max_in_rank(&(stacks->stack_a));
	min = min_in_rank(&(stacks->stack_a));
	med = ((max + min) / 2);
    if (node->position >= med)
    {
        while (node != head)
            rotate_a(&(stacks->stack_a), 1);
    }
    else if (node->position < med)
    {
        while (node != head)
            reverse_a(&(stacks->stack_a), 1);
    }
    return ;
}

void sort_5_op(t_stacks *stacks, t_list *rank_one, t_list *rank_two)
{
	if (rank_one->position == 1 && rank_two->position == 2)
	{
		swap_a(&(stacks->stack_a), 1);
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
        return ;
	}
	else if(rank_one->position == 2 && rank_two->position == 1)
	{
    	push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
        return ;
    }
    sort_5_op_extend(stacks, rank_one);
    sort_5_op_extend(stacks, rank_two);
    sort_5_op(stacks, rank_one, rank_two);
    return ;
}

void sort_4(t_stacks *stacks)
{
	t_list *rank_one;

	position_in_stacks(&(stacks->stack_a));
	rank_one = find_post_with_rank(&(stacks->stack_a), 1);
	if (rank_one->position == 1)
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
	if (rank_one->position == 2)
	{
		swap_a(&(stacks->stack_a), 1);
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
	}
	if (rank_one->position == 3)
	{
		reverse_a(&(stacks->stack_a), 1);
		reverse_a(&(stacks->stack_a), 1);
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
	}
	if (rank_one->position == 4)
	{
		reverse_a(&(stacks->stack_a), 1);
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
	}
    return ;
}

void sort_5(t_stacks *stacks)
{
	t_list *rank_one;
	t_list *rank_two;

	position_in_stacks(&(stacks->stack_a));
	rank_one = find_post_with_rank(&(stacks->stack_a), 1);
	rank_one = find_post_with_rank(&(stacks->stack_a), 2);
	sort_5_op(stacks, rank_one, rank_two);
    small_sort(stacks);
    auto_push_a(&(stacks->stack_a), &(stacks->stack_b), 2, 1);
}

void small_sort(t_stacks *stack)
{
	int     count;

	count = count_in_stack(&(stack->stack_a));
	if (count == 4)
		sort_4(stack);
	if (count == 5)
		sort_5(stack);
    return ;
}
