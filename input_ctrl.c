/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:01:38 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/26 20:55:32 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
char *replace_quote_with_space(char	*str)
{
	size_t	i;
	size_t	len;
	char	*str_without_quote = NULL;
	
	len = ft_strlen(str);
	str_without_quote = (char *)malloc(sizeof(char) * (len + 1));
	if (str_without_quote == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			str_without_quote[i] = ' ';
		else
			str_without_quote[i] = str[i];
		i++;
	}
	str_without_quote[i] = '\0';
	return (str_without_quote);
}
*/

int	input_chk(char *full_str)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (full_str[i])
	{
		j = i + 1;
		if ((full_str[i] != '-' && full_str[i] != ' ') && (full_str[i] < '0' || full_str[i] > '9'))
			return (1);
		if ((full_str[i] == '-') && (full_str[j] < '0' || full_str[j] > '9' || full_str[j] == '\0'))
			return (1);
		i++;
	}
	return (0);
}

int input_ctrl(char **argv_2nd_element_addr)
{
	char	*full_str;
	char	*revised_argv 
	int		*input_chk_res;

	full_str = comb_multi_strs(argv_2nd_element_addr);
	input_chk_res = input_chk(full_str);
	if (!input_chk_res)
	{
		free(full_str);
		return (1);
	}
}

int limit_chk(int **arr_of_int)
{	
	int		position;

	position = 0;
	while (arr_of_int + position)
	{
		if (((arr_of_int + position) > INT_MAX) || ((arr_of_int + position) < INT_MIN))
			return (1);
		position++;
	}
	return (0);
}

int dupli_chk(int **arr_of_int)
{
	int		i;
	int		j;

	i = 0;
	while (arr_of_int[i])
	{
		j = i + 1;
		while (arr_of_int[j])
		{
			if (arr_of_int[i][0] == arr_of_int[j][0])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int limit_n_dupli_ctrl(char **revised_argv)
{
	char	**arr_of_int;
	int		limit_chk_res;
	int		dupli_chk_res;

	arr_of_int = argv_atoi(revised_argv)
	limit_chk_res = limit_chk(arr_of_int);
	depuli_chk_res = dupli_chk(arr_of_int);
	if (!limit_chk_res || !depuli_chk_res)
	{
		free(arr_of_int);
		return (1);
	}
	return (0);
}

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

