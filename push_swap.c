/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:25:18 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/20 15:50:17 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				input_ctrl_res;
	int				limit_n_dupli_res;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (printf("Error\n"));
	input_ctrl_res = input_ctrl(argv + 1);
	limit_n_dupli_res = limit_n_dupli_ctrl(argv + 1);
	if (!input_ctrl_res || !limit_n_dupli_res)
		return (printf("Error\n");
	init_stack_a(&a, argv + 1);
}
