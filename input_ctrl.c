/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:01:38 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/04 15:22:03 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_chk_algo(char *argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		if ((argv[i] != '+' && argv[i] != '-' && argv[i] != ' ')\
		&& (argv[i] < '0' || argv[i] > '9'))
			return (0);
		if ((argv[i] == '+' || argv[i] == '-')\
		&& (argv[j] < '0' || argv[j] > '9' || argv[j] == '\0'))
			return (0);
		if ((argv[i] >= '0' || argv[i] <= '9')\
		&& (argv[j] == '-' || argv[j] == '+'))
			return (0);
		i++;
	}
	return (1);
}

int input_chk(char **argv)
{
	int		i;
	int		res;

	i = 1;
	while (argv[i]) //argv[0] "a.out" argv[1] !@
	{
		res = input_chk_algo(argv[i]);
		if (!res)
			return (0);
		i++;
	}
	return (1);
}

int input_ctrl(char **argv)
{
	int		input_chk_res;

	input_chk_res = input_chk(argv);
	if (!input_chk_res)
		return (0);
	return (1);
}

/*
//the i has to be 1
int limit_chk(char **argv)
{	
	int		i;
	int		atoi_for_limit_chk_res;

	i = 1;	
	while (argv[i])
	{
		atoi_for_limit_chk(argv[i]);
		if (!atoi_for_limit_chk_res)
			return (0);
		i++;
	}
	return (1);
}

int limit_ctrl(char **argv)
{
	int		limit_chk_res;

	limit_chk_res = limit_chk(argv);
	if (!limit_chk_res)
		return (0);
	return (1);
}
*/
/*
int	main(void)
{	
	char	*s = "./a.out \"\"\"\"\"43 \"\"44 45 46 47 48";
	//char	*s = "./a.out \"42 42 45 46 47 48\"";
	//char	*s = "./a.out 42\"44 45 46\"47 48";
	char	c = ' ';
	char	*str_without_quote;
	char	**output;
	size_t	len;

	len = ft_strlen(s);
	str_without_quote = replace_quote_with_space(s, len);
	output = ft_split(str_without_quote, c);
	for (int i = 1; output[i] != NULL; i++)
		printf("%s\n", output[i]);
	return (0);
}
*/

