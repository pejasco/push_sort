/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/04 18:44:01 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_arry_of_ints(int argc, char **argv)
{
	int		i;
	int		j;
	int		*arry_of_ints;
	
	i = 0;
	j = 1;
	arry_of_ints = (int *)malloc(sizeof(int) * argc);
	if (!arry_of_ints)
		return (NULL);
	arry_of_ints[i] = argc;
	while(argv[j])
	{
		arry_of_ints[i] = ft_atoi(argv[j]);
		j++;
		i++;
	}
	return (arry_of_ints);
}

int	*input_mgt(int argc, char **argv)
{
	int			*arry_of_ints;

	if (argc == 1 || (argc == 2 && !argv[1][0]) || !input_ctrl(argv))
	{
		printf("Error - Invalid Input\n");
		return (NULL);
	}
	if (!limit_ctrl(argv))
	{
		printf("Error - Over the Limit of an Int\n");
		return (NULL);
	}
	arry_of_ints = ft_arry_of_ints(argc, argv);
	if (!dupli_ctrl(argc, arry_of_ints))
	{
		printf("Error - Duplicate Input\n");
		return (NULL);
	}
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
			printf("%d\n", temp->data);
			temp = temp->next; 
		}while (temp != *stack);
	}
		printf("--");
		printf("A\n");
}

int	main(int argc, char **argv)
{
	list			*a;
	//stack_node	*b;
	int				*arry_of_ints;	
	a = NULL;
	//b = NULL;
	arry_of_ints = input_mgt(argc, argv);
	if (arry_of_ints == NULL)
		return (1);
	init_stack_a(&a, arry_of_ints);
	print_list(&a);
	return (0);
}
