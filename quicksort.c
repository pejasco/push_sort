/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.london.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:36:39 by mayeung           #+#    #+#             */
/*   Updated: 2024/02/03 19:35:59 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the med = (L + H)/2; everything below that; push to the opp.

#include "push_swap.h"

void	sort_mgt(t_stacks *stacks, int nbr_of_args)
{
	int			high;
	int			low;
	t_qs_stats	stats;

	stacks->nbr_of_args = nbr_of_args;
	if ((if_stack_a_sorted(&(stacks->stack_a))))
		return ;
	if (nbr_of_args <= 3)
	{
		mini_sort(&(stacks->stack_a));
		return ;
	}
	if (nbr_of_args == 5)
	{
		sort_5(stacks);
		return ;
	}
	stats.high = max_in_rank(&(stacks->stack_a));
	stats.low = min_in_rank(&(stacks->stack_a));
	stats.from = 'a';
	quicksort(stacks, stats);
	return ;
}

void	quick_op(t_stacks *stacks, t_qs_stats *stats, char c)
{
	if (c == '1')
	{
		push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
		stats->push++;
	}
	if (c == '2')
	{
		push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
		stats->push++;
	}
	if (c == '3')
	{
		rotate_a(&(stacks->stack_a), 1);
		stats->rotate++;
	}
	if (c == '4')
	{
		rotate_b(&(stacks->stack_b), 1);
		stats->rotate++;
	}
}

void	qs_algo(t_stacks *stacks, t_qs_stats *stats, int med)
{
	if ((stats->high - stats->low) == 1 && (stacks->stack_a->rank) \
		> (stacks->stack_a->next->rank))
		swap_a(&(stacks->stack_a), 1);
	while (stats->rotate-- && !(stats->low == 1 \
		|| stats->high == (stacks->nbr_of_args)))
	{
		if (stats->from == 'a')
			reverse_a(&(stacks->stack_a), 1);
		else
			reverse_b(&(stacks->stack_b), 1);
	}
	quicksort(stacks, (t_qs_stats){.low = med, \
		.high = stats->high, .from = 'a'});
	quicksort(stacks, (t_qs_stats){.low = stats->low, \
		.high = (med - 1), .from = 'b'});
}

void	quicksort(t_stacks *stacks, t_qs_stats stats)
{
	int	med;
	int	i;

	stats.push = 0;
	stats.rotate = 0;
	med = (stats.low + stats.high + 1) / 2;
	i = stats.low;
	if (stats.low > stats.high || (stats.low == stats.high \
		&& stats.from == 'a'))
		return ;
	while (i <= stats.high && stats.push <= (stats.high - stats.low) / 2 \
		&& (stats.high - stats.low > 1 || stats.from == 'b'))
	{
		if (stats.from == 'a' && stacks->stack_a->rank < med)
			quick_op(stacks, &stats, '2');
		else if (stats.from == 'a' && stacks->stack_a->rank >= med)
			quick_op(stacks, &stats, '3');
		else if (stats.from == 'b' && stacks->stack_b->rank >= med)
			quick_op(stacks, &stats, '1');
		else if (stats.from == 'b' && stacks->stack_b->rank < med)
			quick_op(stacks, &stats, '4');
		i++;
	}
	qs_algo(stacks, &stats, med);
}

/*
void    quicksort(t_stacks *stacks, t_qs_stats stats)
{
	int	med;
	int	i;

	med = (stats.low + stats.high + 1) / 2;
	i = stats.low;
	stats.rotate = 0;
	stats.push = 0;
	if (stats.low > stats.high || (stats.low == stats.high && stats.from == 'a'))
		return ;
	while (i <= stats.high && push <= (stats.high - stats.low) / 2 
		&& (stats.high - stats.low > 1 || stats.from == 'b'))
	{
		if (stats.from == 'a' && stacks->stack_a->rank < med)
		{
			push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
			push++;
		}
		else if (stats.from == 'a' && stacks->stack_a->rank >= med)
		{
			rotate_a(&(stacks->stack_a), 1);
			rotate++;
		}
		else if (stats.from == 'b' && stacks->stack_b->rank >= med)
		{
			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
			push++;
		}
		else if (stats.from == 'b' && stacks->stack_b->rank < med)
		{
			rotate_b(&(stacks->stack_b), 1);
			rotate++;
		}
		i++;
	}
	if ((stats.high - stats.low) == 1  && (stacks->stack_a->rank) 
		> (stacks->stack_a->next->rank))
		swap_a(&(stacks->stack_a), 1);
	while (rotate-- && !(stats.low == 1 || stats.high == (stacks->nbr_of_args)))
	{
		if (stats.from == 'a')
			reverse_a(&(stacks->stack_a), 1);
		else
			reverse_b(&(stacks->stack_b), 1);
	}
	quicksort(stacks, (t_qs_stats)\
		{.low = med, .high = stats.high, .from = 'a'});
	quicksort(stacks, (t_qs_stats)\
		{.low = stats.low, .high = (med - 1), .from = 'b'});
}
yeeeeehh*/

/*
void	quicksort(t_stacks *stacks, t_qs_stats *stats, char from, int push)
{
	int	i;
	int rotate;
	int new_push;


	stats->med = (stats->low + stats->high + 1) / 2;
	i = stats->low;
	rotate = 0;
	if (stats->low > stats->high || (stats->low == stats->high && from == 'a'))
		return ;
	while (i <= (stats->high) && push <= (stats->high - stats->low) / 2 
			&& (stats->high - stats->low > 1 || from == 'b'))
	{
		if (from == 'a' && stacks->stack_a->rank < stats->med)
		{
			push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
			push++;
		}
		else if (from == 'a' && stacks->stack_a->rank >= stats->med)
		{
			rotate_a(&(stacks->stack_a), 1);
			rotate++;
		}
		else if (from == 'b' && stacks->stack_b->rank >= stats->med)
		{
			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
			push++;
		}
		else if (from == 'b' && stacks->stack_b->rank < stats->med)
		{
			rotate_b(&(stacks->stack_b), 1);
			rotate++;
		}
		i++;
	}
	if (stats->high - (stats->low) == 1 
		&& ((stacks->stack_a->rank) > (stacks->stack_a->next->rank)))
		swap_a(&(stacks->stack_a), 1);
	new_push = 0;
	while ((rotate)-- && !(stats->low == 0 
		|| stats->high == (stacks->nbr_of_args)))
	{
		if (stats->high - stats->med > 0 && from == 'a')
		{
			while ((stacks->stack_a->rank) < (stats->high + stats->med + 1) / 2)
			{
				push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
				new_push++;
			}
		}
		if (from == 'a')
			reverse_a(&(stacks->stack_a), 1);
		else
			reverse_b(&(stacks->stack_b), 1);
	}
	quicksort(stacks, (t_qs_stats){stats->med, stats->high, stats->med},
	\ 'a', new_push);
	quicksort(stacks, (t_qs_stats){stats->low, stats->med, stats->med}, 'b', 0);
}
*/

/*
void	quicksort(t_stacks *stacks, int low, int high, char from)
{
	t_qs_stats	*stats;
	int			i;

	stats->med = (low + high + 1) / 2;
	i = low;
	stats->rotate = 0;
	stats->push = 0;
	if (low > high || (low == high && from == 'a'))
		return ;
	while (i <= high && push <= (high - low) / 2 \
		&& (high - low > 1 || from == 'b'))
	{
		if (from == 'a' && stacks->stack_a->rank < (stats->med))
		{
			push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
			(stats->push)++;
		}
		else if (from == 'a' && stacks->stack_a->rank >= (stats->med))
		{
			rotate_a(&(stacks->stack_a), 1);
			(stats->rotate)++;
		}
		else if (from == 'b' && stacks->stack_b->rank >= (stats->med))
		{
			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
			(stats->push)++;
		}
		else if (from == 'b' && stacks->stack_b->rank < (stats->med))
		{
			rotate_b(&(stacks->stack_b), 1);
			(stats->rotate)++;
		}
		i++;
	}
	if ((high - low) == 1 && (stacks->stack_a->rank) \
		> (stacks->stack_a->next->rank))
		swap_a(&(stacks->stack_a), 1);
	while ((stats->rotate)-- && !(low == 1 || high == (stacks->nbr_of_args)))
	{
		if (from == 'a')
			reverse_a(&(stacks->stack_a), 1);
		else
			reverse_b(&(stacks->stack_b), 1);
	}
	quicksort(stacks, (stats->med), high, 'a');
	quicksort(stacks, low, ((stats->med) - 1), 'b');
}
*/
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

// void    quicksort(t_stacks *stacks, int low, int high, char from)
// {
// 	int		med;
// 	int		i;
// 	int		rotate;
// 	int		push;

// 	med = (low + high + 1) / 2;
// 	i = low;
// 	rotate = 0;
// 	push = 0;
// 	if (low > high || (low == high && from == 'a'))
// 		return ;
// 	while (i <= high && push <= (high - low) / 2 
// 		&& (high - low > 1 || from == 'b'))
// 	{
// 		if (from == 'a' && stacks->stack_a->rank < med)
// 		{
// 			push_b(&(stacks->stack_a), &(stacks->stack_b), 1);
// 			push++;
// 		}
// 		else if (from == 'a' && stacks->stack_a->rank >= med)
// 		{
// 			rotate_a(&(stacks->stack_a), 1);
// 			rotate++;
// 		}
// 		else if (from == 'b' && stacks->stack_b->rank >= med)
// 		{
// 			push_a(&(stacks->stack_a), &(stacks->stack_b), 1);
// 			push++;
// 		}
// 		else if (from == 'b' && stacks->stack_b->rank < med)
// 		{
// 			rotate_b(&(stacks->stack_b), 1);
// 			rotate++;
// 		}
// 		i++;
// 	}
// 	if ((high - low) == 1  && (stacks->stack_a->rank) 
// 		> (stacks->stack_a->next->rank))
// 		swap_a(&(stacks->stack_a), 1);
// 	while (rotate-- && !(low == 1 || high == (stacks->nbr_of_args)))
// 	{
// 		if (from == 'a')
// 			reverse_a(&(stacks->stack_a), 1);
// 		else
// 			reverse_b(&(stacks->stack_b), 1);
// 	}
// 	quicksort(stacks, med, high, 'a');
// 	quicksort(stacks, low, (med - 1), 'b');
// }

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