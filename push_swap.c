/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <chuleung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/27 17:56:46 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_arry_of_ints(int argc, char **argv)
{
	int		i;
	int		*arry_of_ints;

	i = 1;
	arry_of_ints = (int *)malloc(sizeof(int) * argc);
	if (!arry_of_ints)
		return (NULL);
	arry_of_ints[0] = argc;
	while(argv[i])
	{
		arry_of_ints[i] = ft_atoi(argv[i]);
		i++;
	}
	return (arry_of_ints);
}

int	*input_mgt(int argc, char **argv)
{
	int			*arry_of_ints;

	if (argc == 1 || (argc == 2 && !argv[1][0]) || !input_ctrl(argv))
	{
		printf("Error - Invalid Input(s) T-T\n");
		return (NULL);
	}
	if (!limit_ctrl(argv))
	{
		printf("Error - Input(s) Over Int Limit T-T\n");
		return (NULL);
	}
	arry_of_ints = ft_arry_of_ints(argc, argv);
	if (!dupli_ctrl(argc, arry_of_ints))
	{
		printf("Error - Duplicate Inputs T-T\n");
		return (NULL);
	}
	return (arry_of_ints);
}

void print_list_rank(char stackname, t_list **stack)
{
	t_list *temp;

	if (*stack == NULL)
		printf("Nth\n");
	else
	{
		temp = *stack;
		if (temp->next == *stack)
			printf("%d\n", temp->rank);
		else
		{
			while (temp->next != *stack)
			{
				printf("%d\n", temp->rank);
				temp = temp->next;
			}
			printf("%d\n", temp->rank);
		}
	}
		printf("----\n");
		printf("%c\n\n", stackname);
}


void print_list(char stackname, t_list **stack)
{
	t_list *temp;

	if (*stack == NULL)
		printf("Nth\n");
	else
	{
		temp = *stack;
		if (temp->next == *stack)
			printf("%d\n", temp->data);
		else
		{
			while (temp->next != *stack)
			{
				printf("%d\n", temp->data);
				temp = temp->next;
			}
			printf("%d\n", temp->data);
		}
	}
		printf("----\n");
		printf("%c\n\n", stackname);
}
/*
void stack_mgt(t_list **stack_a, t_list **stack_b)
{
	//int i;
	
	*stack_b = NULL;
	//for(i = 1; i < 10; i++)
	//	push_b(stack_a, stack_b);
	//swap_a(stack_a);
	//swap_b(stack_b);
	//rotate_a(stack_a);
	//rotate_b(stack_b);
	//push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	//rotate_anb(stack_a, stack_b);
	//rotate_b(stack_b);
	reverse_a(stack_a);
	reverse_b(stack_b);
	reverse_anb(stack_a, stack_b);
}
*/
int	main(int argc, char **argv)
{
	t_stacks		stacks;
	t_list			*a_copy;
	int				*arry_of_ints;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	arry_of_ints = input_mgt(argc, argv);
	if (arry_of_ints == NULL)
		return (1);
	init_stack_a(&(stacks.stack_a), arry_of_ints);
	a_copy = copy_init_a(&(stacks.stack_a));
	a_copy = rank_in_stack(&a_copy);
	rank_from_copy_a_to_a(&(stacks.stack_a), &a_copy);
	sort_mgt(&stacks, (argc -1));
	//print_list('a', &a);
	//print_list_rank('a', &a);
	//sort_mgt_a_to_b(&(stacks->stack_a), &(stacks->stack_b), (argc-1));
	//print_list('A', &(stacks.stack_a));
	//print_list_rank('A', &(stacks.stack_a));
	// print_list('B', &(stacks.stack_b));
	// print_list_rank('B', &(stacks.stack_b));
	/*test_tail = tail_find(&a);
	if (test_tail == NULL)
		return (0);
	else
	{
		test = test_tail->data;
		printf("%d", test);
	}
	return (0);*/
}
