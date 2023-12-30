/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/29 21:07:50 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**input_mgt(int argc, char **argv)
{
	char		*full_str;
	char		**revised_argv;
	int			**arry_of_ints;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (NULL);
	full_str = comb_multi_strs(argv + 1);
	if (!input_ctrl(full_str)
		return (NULL);
	revised_argv = ft_split(full_str, ' ');
	free(full_str);
	arry_of_ints = argv_atoi(revised argv);
	if (!limit_n_dupli_ctrl(arry_of_ints))
		return (NULL);
	return (arry_of_ints);
}

int	main(int argc, char **argv)
{
	stack_node	*a;
	stack_node	*b;
	int				**arry_of_ints;	

	a = NULL;
	b = NULL;
	arry_of_ints = input_mgt(argc, argv);
	if (arry_of_ints = NULL)
		return (1);
	init_stack_a(&a, arry_of_ints);
	return (0);
}
