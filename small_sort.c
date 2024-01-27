/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:39:16 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/27 22:53:55 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_5_op_extend(t_stacks *stacks, t_list *node, int tgt_pos)
{
    int med;
	int curr_pos;

	med = 3;
	curr_pos = node->position;
    if (curr_pos >= med)
    {
        while (curr_pos != tgt_pos)
		{
			rotate_a(&(stacks->stack_a), 1);
			position_in_stacks(&(stacks->stack_a));
			curr_pos = node->position;
		}
    }
    else if (node->position < med)
    {
        while (curr_pos != tgt_pos)
		{
			reverse_a(&(stacks->stack_a), 1);
			position_in_stacks(&(stacks->stack_a));
			curr_pos = node->position;
		}
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
    sort_5_op_extend(stacks, rank_one, 2);
    sort_5_op_extend(stacks, rank_two, 1);
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
	auto_push_b(&(stacks->stack_a), &(stacks->stack_b), 2, 1);
	mini_sort(&(stacks->stack_a));
	while (!count_in_stack(&(stacks->stack_b)))
	{
		while()
		{


		}
		push_a(&(stacks->stack_a), &(stacks->stack_b), 1); 
	}

}





/*
void sort_5(t_stacks *stacks)
{
	t_list *rank_one;
	t_list *rank_two;

	position_in_stacks(&(stacks->stack_a));
	rank_one = find_post_with_rank(&(stacks->stack_a), 1);
	rank_two = find_post_with_rank(&(stacks->stack_a), 2);
	sort_5_op(stacks, rank_one, rank_two);
    small_sort(stacks);
    auto_push_a(&(stacks->stack_a), &(stacks->stack_b), 2, 1);
}
*/

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
