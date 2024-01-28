/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:39 by mayeung           #+#    #+#             */
/*   Updated: 2024/01/28 18:02:52 by Scofield         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the med = (L + H)/2; everything below that; push to the opp.

#include "push_swap.h"

void	sort_mgt(t_stacks *stacks, int nbr_of_args)
{
	t_sort_para	params;

	params.stacks = stacks;
	params.low = min_in_rank(&(stacks->stack_a));
	params.high = max_in_rank(&(stacks->stack_a));
	params.from = 'a';
	stacks->nbr_of_args = nbr_of_args;
	if ((if_stack_a_sorted(&(stacks->stack_a))))
		return ;
	if (nbr_of_args <= 3)
	{
		mini_sort(&(stacks->stack_a));
		return ;
	}
	if (nbr_of_args == 4 || nbr_of_args == 5)
	{
		small_sort(stacks);
		return ;
	}
	quicksort(&params);
	return ;
}

t_op_count	perform_operations(t_sort_para *params, int med)
{
	t_op_count	op;

	op.push = 0;
	op.rotate = 0;
	if (params->from == 'a' && params->stacks->stack_a->rank < med)
	{
		push_b(&(params->stacks->stack_a), &(params->stacks->stack_b), 1);
		op.push++;
	}
	else if (params->from == 'a' && params->stacks->stack_a->rank >= med)
	{
		rotate_a(&(params->stacks->stack_a), 1);
		op.rotate++;
	}
	else if (params->from == 'b' && params->stacks->stack_b->rank >= med)
	{
		push_a(&(params->stacks->stack_a), &(params->stacks->stack_b), 1);
		op.push++;
	}
	else if (params->from == 'b' && params->stacks->stack_b->rank < med)
	{
		rotate_b(&(params->stacks->stack_b), 1);
		op.rotate++;
	}
	return (op);
}

t_op_count	partition(t_sort_para *params)
{
	t_op_count	op;
	int			med;
	int			i;

	med = (params->low + params->high + 1) / 2;
	i = params->low;
	while (i <= params->high && op.push <= (params->high - params->low) / 2
		&& (params->high - params->low > 1 || params->from == 'b'))
	{
		op = perform_operations(params, med);
		i++;
	}
	return (op);
}

void	swap_and_reverse(t_sort_para *params, int rotate)
{
	if ((params->high - params->low) == 1 && (params->stacks->stack_a->rank)
		> (params->stacks->stack_a->next->rank))
		swap_a(&(params->stacks->stack_a), 1);
	while (rotate-- && !(params->low == 1 || \
		params->high == (params->stacks->nbr_of_args)))
	{
		if (params->from == 'a')
			reverse_a(&(params->stacks->stack_a), 1);
		else
			reverse_b(&(params->stacks->stack_b), 1);
	}
}

void	quicksort(t_sort_para *params)
{
	t_op_count	op;

	if (params->low > params->high || \
		(params->low == params->high && params->from == 'a'))
		return ;
	op = partition(params);
	swap_and_reverse(params, op.rotate);
	params->low = (params->low + params->high + 1) / 2;
	quicksort(params);
	params->high = ((params->low + params->high + 1) / 2 - 1);
	quicksort(params);
}

/*
void	sort_mgt(t_stacks *stacks, int nbr_of_args)
{
	int		high;
	int		low;

	stacks->nbr_of_args = nbr_of_args;
	if ((if_stack_a_sorted(&(stacks->stack_a))))
		return ;
	if (nbr_of_args <= 3)
	{
		mini_sort(&(stacks->stack_a));
		return ;
	}
	if (nbr_of_args == 4 || nbr_of_args == 5)
	{
		small_sort(stacks);
		return ;
	}
	high = max_in_rank(&(stacks->stack_a));
	low = min_in_rank(&(stacks->stack_a));
	quicksort(stacks, low, high, 'a');
	return ;
}

t_op_count	perform_operations(t_stacks *stacks, int med, char from)
{
	t_op_count	op;

	op.rotate = 0;
	op.push = 0;
	if (from == 'a' && stacks->stack_a->rank < med)
	{
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
		op.push++;
	}
	else if (from == 'a' && stacks->stack_a->rank >= med)
	{
		rotate_a(&(stacks->stack_a), 1);
		op.rotate++;
	}
	else if (from == 'b' && stacks->stack_b->rank >= med)
	{
		push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
		op.push++;
	}
	else if (from == 'b' && stacks->stack_b->rank < med)
	{
		rotate_b(&(stacks->stack_b), 1);
		op.rotate++;
	}
	return (op);
}

t_op_count	partition(t_stacks *stacks, int low, int high, char from)
{
	t_op_count	op;
	int			med;
	int			i;

	med = (low + high + 1) / 2;
	i = low;
	while (i <= high && op.push <= (high - low) / 2
		&& (high - low > 1 || from == 'b'))
	{
		op = perform_operations(stacks, med, from);
		i++;
	}
	return (op);
}

void	swap_and_reverse(t_stacks *stacks, int low, int high
	, char from, int rotate)
{
	if ((high - low) == 1 && (stacks->stack_a->rank)
		> (stacks->stack_a->next->rank))
		swap_a(&(stacks->stack_a), 1);
	while (rotate-- && !(low == 1 || high == (stacks->nbr_of_args)))
	{
		if (from == 'a')
			reverse_a(&(stacks->stack_a), 1);
		else
			reverse_b(&(stacks->stack_b), 1);
	}
}

void	quicksort(t_stacks *stacks, int low, int high, char from)
{
	t_op_count	op;

	if (low > high || (low == high && from == 'a'))
		return ;
	op = partition(stacks, low, high, from);
	swap_and_reverse(stacks, low, high, from, op.rotate);
	quicksort(stacks, (low + high + 1) / 2, high, 'a');
	quicksort(stacks, low, ((low + high + 1) / 2 - 1), 'b');
}
*/
/*
void    quicksort(t_stacks *stacks, int low, int high, char from)
{
	int		med;
	int		i;
	int		rotate;
	int		push;

	med = (low + high + 1) / 2;
	i = low;
	rotate = 0;
	push = 0;
	if (low > high || (low == high && from == 'a'))
		return ;
	while (i <= high && push <= (high - low) / 2 
		&& (high - low > 1 || from == 'b'))
	{
		if (from == 'a' && stacks->stack_a->rank < med)
		{
			push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
			push++;
		}
		else if (from == 'a' && stacks->stack_a->rank >= med)
		{
			rotate_a(&(stacks->stack_a), 1);
			rotate++;
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
	if ((high - low) == 1  && (stacks->stack_a->rank) 
		> (stacks->stack_a->next->rank))
		swap_a(&(stacks->stack_a), 1);
	while (rotate-- && !(low == 1 || high == (stacks->nbr_of_args)))
	{
		if (from == 'a')
			reverse_a(&(stacks->stack_a), 1);
		else
			reverse_b(&(stacks->stack_b), 1);
	}
	quicksort(stacks, med, high, 'a');
	quicksort(stacks, low, (med - 1), 'b');
}
*/
/*
void    quicksort_old(t_stacks *stacks, 
	int low, int high, char from, int pa_count)
{
	int	med;
	int	i;
	int	rb_count;

	med = (low + high + 1) / 2;
	i = low;
	rb_count = 0;
	if (low > high || ((if_stack_a_sorted(&(stacks->stack_a))) && from == 'a'))
		return ;
	while (i <= (high-3) && from == 'b' 
		|| ((if_stack_a_sorted(&(stacks->stack_a))) 
		&& from == 'a' && max_in_stack))
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
		mini_sort_rev(&(stacks->stack_a), &(stacks->stack_b));
	while (rb_count--)
		reverse_b(&(stacks->stack_b), 1);
	quicksort(stacks, med, high, 'a', 0);
	quicksort(stacks, low, med - 1, 'b', pa_count);
}
*/
