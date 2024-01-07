/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/06 19:55:32 by chuleung         ###   ########.fr       */
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

void print_list(char stackname, list **stack)
{
	list *temp;

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

void stack_mgt(list **stack_a, list **stack_b)
{
	int i;
	
	*stack_b = NULL;
	for(i = 1; i < 10; i++)
		push_b(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	list			*a;
	list			*b;
	int				*arry_of_ints;
	int				test;
	list			*test_tail;

	a = NULL;
	b = NULL;
	arry_of_ints = input_mgt(argc, argv);
	if (arry_of_ints == NULL)
		return (1);
	init_stack_a(&a, arry_of_ints);
	stack_mgt(&a, &b);
	print_list('A', &a);
	print_list('B', &b);
	test_tail = tail_find(&a);
	test = test_tail->data;
	printf("%d", test);
	return (0);
}
