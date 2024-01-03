/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/03 21:29:47 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arry_of_ints(char **argv)
{
	int		i;
	int		count;
	int		*arry_of_ints;
	
	i = 0;
	count = arry_of_ints(argv + 1)
	arry_of_ints = (int *)malloc(sizeof(int) * (count) + 1)
	if (!arry_of_ints)
		return (NULL);
	arry_of_int[i] = count;
	while(argv + 1)
	{
		arry_of_ints[i] = ft_atoi(argv + 1);
		argv++;
		i++;
	}
	return (1);
}

int	*input_mgt(int argc, char **argv)
{
	int			*arry_of_ints;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	if (!input_ctrl(argv))
		return (NULL);
	if (!limit_ctrl(argv))
		return (NULL);
	arry_of_ints = arry_of_ints(argv);
	if (!dupli_ctrl(arry_of_ints))
		return (NULL);
	return (arry_of_ints);
}

void print_list(list **stack)
{
	list *temp;

	if (*stack == NULL)
		printf("No element in the list");
	else
	{
		temp = *stack;
		do
		{
			printf("%d\n", temp->value);
			temp = temp->next; 
		}while (temp != *stack);
	}
		printf(""__"");
		printf("A\n");
}

int	main(int argc, char **argv)
{
	stack_node		*a;
	//stack_node		*b;
	int				*arry_of_ints;	
	a = NULL;
	//b = NULL;
	arry_of_ints = input_mgt(argc, argv);
	if (arry_of_ints = NULL)
		return (1);
	init_stack_a(&a, arry_of_ints);
	print_list(&a);
	return (0);
}
