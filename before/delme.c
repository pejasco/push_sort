/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:39:14 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/27 10:29:10 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		max;
	int		min;
	//int		maxplus1;
	//int		minminus1;

	max = INT_MAX;
	min = INT_MIN;
	//maxplus1 = INT_MAX + 1;
	//minminus1 = INT_MIN - 1;
	printf("Max        : %d\n", max);
	printf("Min        : %d\n", min);
	//printf("Max Plus 1 : %d\n", maxplus1);
	//printf("Min Minus 1: %d\n", minminus1);
	return (0);
}
