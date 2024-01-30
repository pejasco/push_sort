/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:39:16 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/30 15:39:20 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "push_swap.h"

void	sort_4_push_b(t_stacks *stacks)
{
	t_list	*rank_one;

	position_in_stacks(&(stacks->stack_a));
	rank_one = find_post_with_rank(&(stacks->stack_a), 1);
	if (rank_one->position == 1)
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
	else if (rank_one->position == 2)
	{
		swap_a(&(stacks->stack_a), 1);
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
	}
	else if (rank_one->position == 3)
	{
		reverse_a(&(stacks->stack_a), 1);
		reverse_a(&(stacks->stack_a), 1);
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
	}
	else if (rank_one->position == 4)
	{
		reverse_a(&(stacks->stack_a), 1);
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
	}
}

void	sort_4_mgt(t_stacks *stacks)
{
	sort_4(stacks);
	mini_sort(stacks);


}

void	sort_5_op_pt2(t_stacks *stacks, int rank)
{
	int	reverse_ra_or_rra;

	if (rank == 3)
	{
		reverse_ra_or_rra = check_moves_before_push(stacks, rank);
		ra_n_rra_for_push_a(stacks, rank);
		push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
		auto_reverse_a(&(stacks->stack_a), reverse_ra_or_rra, 1);
	}
	else if (rank == 4)
	{
		reverse_ra_or_rra = check_moves_before_push(stacks, rank);
		if (reverse_ra_or_rra)
		{
			reverse_a(&(stacks->stack_a), 1);
			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
			auto_rotate_a(&(stacks->stack_a), 2, 1);
		}
		else
		{
			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
			rotate_a(&(stacks->stack_a), 1);
		}
	}
}

void	sort_5_op(t_stacks *stacks)
{
	t_list	*stack_b_current;
	int		rank;

	stack_b_current = stacks->stack_b;
	rank = stack_b_current->rank;
	if (rank == 1)
		push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
	else if (rank == 5)
	{
		push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
		rotate_a(&(stacks->stack_a), 1);
	}
	else if (rank == 2)
	{
		if (stacks->stack_a->rank == 1)
		{
			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
			swap_a(&(stacks->stack_a), 1);
		}
		else
			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
	}
	else
		sort_5_op_pt2(stacks, rank);
}

void	sort_5(t_stacks *stacks)
{
	t_list	*stack_b_current;

	stack_b_current = stacks->stack_b;
	auto_push_b(&(stacks->stack_a), &(stacks->stack_b), 2, 1);
	mini_sort(&(stacks->stack_a));
	if (stack_b_current->rank < stack_b_current->next->rank)
		swap_b(&(stacks->stack_b), 1);
	sort_5_op(stacks);
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

/*
void	small_sort(t_stacks *stack)
{
	int	count;

	count = count_in_stack(&(stack->stack_a));
	if (count == 4)
		sort_4(stack);
	if (count == 5)
		sort_5(stack);
	return ;
}
*/
