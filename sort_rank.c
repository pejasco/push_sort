/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:17:22 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/28 18:52:42 by Scofield         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rank_algo(t_list *copy_of_a, t_list *copy_of_b)
{
	int		min;
	t_list	*current_a;
	int		i;
	int		count;

	i = 0;
	count = count_in_stack(&copy_of_a);
	current_a = copy_of_a;
	min = min_in_stack(&copy_of_a);
	while (i < count)
	{
		min = min_in_stack(&copy_of_a);
		if (current_a->data == min)
			push_b(&copy_of_a, &copy_of_b, 0);
		while (current_a->data != min)
		{
			rotate_a(&copy_of_a, 0);
			current_a = copy_of_a;
			if (current_a->data == min)
				push_b(&copy_of_a, &copy_of_b, 0);
		}
		i++;
	}
	return (copy_of_b);
}

t_list	*rank_assign_to_copy_b(t_list *copy_of_b)
{
	t_list	*current_b;
	int		i;
	int		count;

	if (copy_of_b == NULL)
		return (NULL);
	count = count_in_stack(&copy_of_b);
	copy_of_b->rank = (count);
	current_b = copy_of_b->next;
	i = (count - 1);
	while (current_b != copy_of_b)
	{
		current_b->rank = i;
		current_b = current_b->next;
		i--;
	}
	return (copy_of_b);
}

t_list	*push_copy_b_to_copy_a(t_list *copy_of_a, t_list *copy_of_b)
{
	int	rank;

	rank = -1;
	if (copy_of_b == NULL)
		return (NULL);
	if (copy_of_b->next == copy_of_b)
	{
		rank = copy_of_b->rank;
		push_a(&copy_of_a, &copy_of_b, 0);
		copy_of_a->rank = rank;
		return (NULL);
	}
	while (copy_of_b->next != copy_of_b)
	{
		rank = copy_of_b->rank;
		push_a(&copy_of_a, &copy_of_b, 0);
		copy_of_a->rank = rank;
	}
	rank = copy_of_b->rank;
	push_a(&copy_of_a, &copy_of_b, 0);
	copy_of_a->rank = rank;
	return (copy_of_a);
}

t_list	*rank_in_stack(t_list **stack)
{
	t_list		*copy_of_a;
	t_list		*copy_of_b;
	t_list		*current_a;

	if (*stack == NULL || stack == NULL)
		return (NULL);
	current_a = *stack;
	copy_of_a = current_a;
	copy_of_b = NULL;
	if (copy_of_a->next == copy_of_a)
		return (copy_of_a);
	copy_of_b = rank_algo(copy_of_a, copy_of_b);
	copy_of_b = rank_assign_to_copy_b(copy_of_b);
	copy_of_a = NULL;
	copy_of_a = push_copy_b_to_copy_a(copy_of_a, copy_of_b);
	return (copy_of_a);
}

void	rank_from_copy_a_to_a(t_list **a, t_list **copy_of_a)
{
	t_list	*current_in_a;
	t_list	*current_in_copy;
	int		count;
	int		i;

	if (a == NULL && copy_of_a == NULL)
		return ;
	i = 0;
	if (count_in_stack(a) != count_in_stack(copy_of_a))
		return ;
	count = count_in_stack(copy_of_a);
	current_in_a = *a;
	current_in_copy = *copy_of_a;
	while (i < count)
	{
		current_in_a = *a;
		while (current_in_copy->data != current_in_a->data)
			current_in_a = current_in_a->next;
		current_in_a->rank = current_in_copy->rank;
		current_in_copy = current_in_copy->next;
		i++;
	}
	free_whole_stack(copy_of_a);
}
