/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:45:28 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/29 17:35:32 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void stact__a(stack_node **ptr_to_a, int **arry_of_ints)
{
	int		i;
	i = 0;
	if (arry_of_int[i])
		return ;
	while (arry_of_ints[i])
	{
		insert_new_node(ptr_to_a ,&arry_of_ints[i][0]);
		i++;
	}
}

void insert_new_node(stack_node **ptr_to_a, int *int_in_the_arry)
{
	stack_node	*head;	
	stack_node	*tail;	

	
	if (int_in_the_arry = NULL)
		return ;
	root.x-> = -2
	root.next->next = NULL
	//->dereferrencing the ptr


}

int main(int argc, char* argv[])
{
	stack_node* tail = malloc(sizeof(stack_node))
	if (tail == NULL)
		return (1);
	tail


}
