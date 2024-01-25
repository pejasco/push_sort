/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:33:16 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/25 22:51:36 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3_algo(t_list **stack, t_list **fir_node, t_list **sec_node, t_list **thi_node)
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

void sort_2_rank(t_list **stack, int rank_exist)
{
	int     max;
	int     min;
	int     i;
	t_list    *current;

	if (rank_exist == 1)
		return ;
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

void sort_3_rank(t_list **stack, int rank_exist)
{
	int     max;
	int     min;
	int     i;
	t_list    *current;

	if (rank_exist == 1)
		return ;
	i = 0;
	max = max_in_stack(stack);
	printf("max--->%d\n", max);
	min = min_in_stack(stack);
	printf("min--->%d\n", min);
	current = *stack;
	while (i < 2)
	{
		if (current->data == max)
			(current)->rank = 3;
		else if (current->data == min)
			(current)->rank = 1;
		else
			(current)->rank = 2;
		current = current->next;
		i++;
	}
}

int rank_exist(t_list **stack)
{
	if ((*stack)->rank > -1)
		return (1);
	else
		return (0);
}

void sort_2(t_list **stack)
{
	int     exist_res;

	exist_res = rank_exist(stack);
	sort_2_rank(stack, exist_res);
	if((*stack)->rank > (*stack)->next->rank)
		swap_a(stack, 1);
}

void sort_3(t_list **stack)
{
	t_list    *fir_node;
	t_list    *sec_node;
	t_list    *thi_node;
	int     exist_res;

	exist_res = rank_exist(stack);
	sort_3_rank(stack, exist_res);
	fir_node = *stack; 
	sec_node = (*stack)->next;
	thi_node = (*stack)->next->next;
	sort_3_algo(stack, &fir_node, &sec_node, &thi_node);
}

void position_in_stacks(t_list **stack)
{
	t_list *head;
	t_list *current;

	head = *stack;
	current = head->next;
	current->position = 0;
	if (current == *stack)
		current->position = 1;
	while (current != *stack)
	{
		current->position++;
		current->next;
	}
}

t_list *find_post_with_rank(t_list **stack, int rank)
{
	t_list *target;

	target = *stack;
	while (target->rank != rank)
		target = target->next;
	return (target);
}

void sort_5_op(t_stacks *stacks, t_list *rank_five)
{





}

void sort_4(t_stacks *stacks)
{
	t_list *rank_one;

	position_in_stacks(stacks->stack_a);
	rank_one = find_post_with_rank(&(stacks->stack_a), 1);
	sort_4_op(stacks, rank_one);
	if (rank_one->position == 1)
		push_b(stacks->stack_a, stacks->stack_b, 1);
	if (rank_one->position == 2)
	{
		swap_a(stacks->stack_a, 1);
		push_b(stacks->stack_a, stacks->stack_b, 1);
	}
	if (rank_one->position == 3)
	{
		reverse_a(stacks->stack_a, 1);
		reverse_a(stacks->stack_a, 1);
		push_b(stacks->stack_a, stacks->stack_b, 1);
	}
	if (rank_one->position == 4)
	{
		reverse_a(stacks->stack_a, 1);
		push_b(stacks->stack_a, stacks->stack_b, 1);
	}
}

void sort_5(t_stacks *stacks)
{
	t_list *rank_one;
	t_list *rank_two;

	position_in_stacks(stacks->stack_a);
	rank_one = find_post_with_rank(&(stacks->stack_a), 1);
	sort_4_op(stacks, rank_four);
	if (rank_four->position == 1)
		push_b(stacks->stack_a, stacks->stack_b, 1);
	if (rank_four->position == 2)
	{
		swap_a(stacks->stack_a, 1);
		push_b(stacks->stack_a, stacks->stack_b, 1);
	}
	if (rank_four->position == 3)
	{
		reverse_a(stacks->stack_a, 1);
		reverse_a(stacks->stack_a, 1);
		push_b(stacks->stack_a, stacks->stack_b, 1);
	}
	if (rank_four->position == 4)
	{
		reverse_a(stacks->stack_a, 1);
		push_b(stacks->stack_a, stacks->stack_b, 1);
	}

}


void small_sort(t_list **stack)
{
	int     count;

	count = count_in_stack(stack);
	if (count == 4)
		sort_2(stack);
	if (count == 5)
		sort_3(stack);
}

void mini_sort(t_list **stack)
{
	int     count;

	count = count_in_stack(stack);
	if (count <= 1 || count > 3)
		return ;
	if (count == 2)
		sort_2(stack);
	if (count == 3)
		sort_3(stack);
}

