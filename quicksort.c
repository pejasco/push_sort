/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:39 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/20 22:38:27 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the med = (L + H)/2; everything below that; push to the opp.

#include "push_swap.h"

void	sort_mgt(t_stacks *stacks, int nbr_of_args)
{
	int		high;
	int		low;
	int		root;

	stacks->nbr_of_args = nbr_of_args;
	if ((if_stack_a_sorted(&(stacks->stack_a))))
		return ;
	high = max_in_rank(&(stacks->stack_a));
	low = min_in_rank(&(stacks->stack_a));
	//printf("min:%d\n", low);
	//printf("max:%d\n", high);
	quicksort(stacks, low, high, 'a');
	return ;
}

void    quicksort(t_stacks *stacks, int low, int high, char from)
{
	int	med;
	int	i;
	int	rotate;
	int	push;

	med = (low + high + 1) / 2;
	i = low;
	rotate = 0;
	push = 0;
	if (low > high || (low == high && from == 'a'))
		return ;
	while (i <= high && ((from == 'a') || ((push <= (high - low) / 2) && (from == 'b')) && (high - low > 1 || from == 'b')))
	{
		if (from == 'a')
		{
			push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
		}
		else if (from == 'b' && stacks->stack_b->rank >= med)
		{
			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
			push++;
		}
		else if (from == 'b' && stacks->stack_b->rank < med)
		{
			rotate_b(&(stacks->stack_b), 1);
			rotate++;
		}
		i++;
	}
	if ((high - low) == 1  && (stacks->stack_a->rank) > (stacks->stack_a->next->rank))
		swap_a(&(stacks->stack_a), 1);
	while (rotate-- && !(low == 1 || high == (stacks->nbr_of_args)))
	{
		if (from == 'a')
			reverse_a(&(stacks->stack_a), 1);
		else
			reverse_b(&(stacks->stack_b), 1);
	}
	//quicksort(stacks, med, high, 'a');
	//quicksort(stacks, low, (med - 1), 'b');
}

/*
void    quicksort_old(t_stacks *stacks, int low, int high, char from, int pa_count)
{
	int	med;
	int	i;
	int	rb_count;

	med = (low + high + 1) / 2;
	i = low;
	rb_count = 0;
	if (low > high || ((if_stack_a_sorted(&(stacks->stack_a))) && from == 'a'))
		return ;
	while (i <= (high-3) && from == 'b' || ((if_stack_a_sorted(&(stacks->stack_a))) && from == 'a' && max_in_stack))
	{
		pa_count = 0;
		if (from == 'b' && stacks->stack_b->rank >= med)
		{
			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
			pa_count++;
		}
		else if (from == 'b' && stacks->stack_b->rank < med)
		{
			rotate_b(&(stacks->stack_b), 1);
			rb_count++;
		}
		if (from == 'a' && !(if_stack_a_sorted(&(stacks->stack_a))))
			auto_push_b(&(stacks->stack_a), &(stacks->stack_b), pa_count, 1);
		i++;
	}
	if ((high - low) < 4 && from == 'b')
		small_sort_rev(&(stacks->stack_a), &(stacks->stack_b));
	while (rb_count--)
		reverse_b(&(stacks->stack_b), 1);
	quicksort(stacks, med, high, 'a', 0);
	quicksort(stacks, low, med - 1, 'b', pa_count);
}
*/
