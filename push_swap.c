/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/26 20:55:26 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*full_str;
	int				**argv_atoi;	

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (printf("Error\n"));
	full_str = comb_multi_str(argv + 1);
	revised_argv = ft_split(full_str, ' ');
	if (!input_ctrl(full_str) || !limit_n_dupli_res(revised_argv))
		return (printf("Error\n"));
	init_stack_a(&a, argv + 1);
	return (0);
}
