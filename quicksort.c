/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:39 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/18 23:20:14 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the med = (L + H)/2; everything below that; push to the opp.

#include "push_swap.h"

void	sort_mgt(t_stacks *stacks, int nbr_of_args)
{
	int		high;
	int		low;
	int		root;

	if (if_stack_a_sorted(&(stacks->stack_a)))
		return ;
	root = finding_root(nbr_of_args);
	init_sort_a_to_b(stacks, nbr_of_args, root);
	//high = max_in_stack(&(stacks->stack_b));
	//low = min_in_stack(&(stacks->stack_b));
	//quicksort(stacks, low, high, 'b', 0);
	return ;
}

void    quicksort(t_stacks *stacks, int low, int high, char from, int pa_count)
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
	//quicksort(stacks, med, high, 'a', 0);
	//quicksort(stacks, low, med - 1, 'b', pa_count);
}
