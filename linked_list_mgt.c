/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_mgt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Scofield <Scofield@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:34:29 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/28 15:31:11 by Scofield         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*addtoempty(int data, int rank)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	temp->prev = temp;
	temp->data = data;
	temp->rank = rank;
	temp->next = temp;
	return (temp);
}

t_list	*push(t_list *tail, int data, int rank)
{
	t_list	*newp;
	t_list	*temp;

	newp = NULL;
	temp = NULL;
	newp = addtoempty(data, rank);
	if (tail == NULL)
		return (newp);
	else
	{
		temp = tail->next;
		newp->prev = tail;
		newp->next = temp;
		temp->prev = newp;
		tail->next = newp;
		return (tail);
	}
}

t_list	*append(t_list *tail, int data, int rank)
{
	t_list	*newp;
	t_list	*temp;

	newp = NULL;
	temp = NULL;
	newp = addtoempty(data, rank);
	if (tail == NULL)
		return (newp);
	else
	{
		temp = tail->next;
		newp->next = temp;
		newp->prev = tail;
		tail->next = newp;
		temp->prev = newp;
		tail = newp;
		return (tail);
	}
}

t_list	*pop(t_list *tail, t_list **stack)
{
	t_list	*temp;

	if (tail == NULL)
		return (tail);
	temp = tail->next;
	if (temp == tail)
	{
		free(tail);
		*stack = NULL;
		return (NULL);
	}
	tail->next = temp->next;
	temp->next->prev = tail;
	*stack = temp->next;
	free(temp);
	return (tail);
}

t_list	*poplast(t_list *tail)
{
	t_list	*temp;

	if (tail == NULL)
		return (tail);
	temp = tail->prev;
	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return (tail);
	}
	temp->next = tail->next;
	tail->next->prev = temp;
	free(tail);
	tail = temp;
	return (tail);
}

/*
void print(t_list *tail)
{
	if(tail == NULL)
		printf("No element in the list");
	else
	{
		struct t_list *temp = tail->next;
		do
		{
			printf("%d", temp->data);
			temp = temp->next;
		} while(temp != tail->next);
	}
	printf("\n");
}
*/

/*
typedef struct s_node
{
	struct s_node *prev;
	int value;
	struct s_node *next;
} list;

int main(void)
{
	int	**ptr_to_arry;
	int	*
	t_list *a;
	t_list *b;
	
	i = 0;
	number = 5;
	ptr_to_arry = (int **)malloc(sizeof(int *) * 5);
	while (ptr_to_arry[i])
	{
		ptr_to_arry[i][0] = malloc(sizeof(int));
		ptr_to_arry[i][0] = (number * 5);
		i++;
	}
	
}

	
	struct t_list *tail;
	tail = NULL;
 	tail = addtoempty(34);
	tail = append(tail, 45);
	tail = append(tail, 56);

	printf("List before Deletion: ");
	print(tail);
	//tail = pop(tail);
	tail = delast(tail);
	printf("List after Deletion: ");
	print(tail);
	return (0);
}
*/
