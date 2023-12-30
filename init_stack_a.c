/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:45:28 by chuleung          #+#    #+#             */
/*   Updated: 2023/12/30 22:25:57 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void init_stack_a(stack_node **ptr_to_stack, int **arry_of_ints)
{
	stack_node *tail_aka_bottom = NULL;
	stack_node *head_aka_top = NULL;

	while(
	init_stack_node(&tail_aka_bottom, &head_aka_top, arry_of_ints[i][0]);
}

void init_stack_node(stack_node **tail_aka_bottom, stack_node **tail_aka_top, int value)
{
	stack_node *new_node = malloc(sizeof(stack_node));
	if (new_node == NULL)
		return;
	new_node->x = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	*tail = new_node;
	*head = new_node;
}

void insert_beggining(node **tail_aka_bottom, int value)
{
	stack_node *new_node = malloc(sizeof(stack_node));
	if (new_node = NULL)
		return;
	new_node->nbr = value;
	new_node->prev = NULL;
	new_node->next = *tail_aka_bottom;
	if (*tail_aka_bottom)
		(*tail_aka_bottom)->prev = new_node;
	*tail = new_node;
}







void insert_new_node
{
	stack_node	*tail_aka_top;
	stack_node	*head_aka_bottom;	
	
	head_aka_top = NULL;
	tail_aka_bottom = NULL;
	if (int_in_the_arry = NULL)
		return ;
	root.x-> = -2
	root.next->next = NULL
	//->dereferrencing the ptr


}

v




int main(int argc, char* argv[])
{
	stack_node* tail = malloc(sizeof(stack_node))
	if (tail == NULL)
		return (1);
	tail


}
