/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_mgt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 19:34:29 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/03 21:30:37 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

list *addtoempty(int data)
{
	list *temp = malloc(sizeof(list));
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;
	return temp;
}

list *addatbeg(list *tail, int data)
{
	list *newp;
	list *temp;

	newp = NULL;
	temp = NULL;
	newp = addtoempty(data);
	if(tail == NULL)
		return newp;
	else
	{
		temp = tail->next;
		newp->prev = tail;
		newp->next = temp;
		temp->prev = newp;
		tail->new = newp;
		return tail;
	}
}

list *addatend(list *tail, int data)
{
	list *newp;
	list *temp;

	newp = NULL;
	temp = NULL;
	newp = addtoempty(data);
	if (tail == NULL)
		return newp;
	else
	{
		temp = tail->next;
		newp->next = temp;
		newp->prev = tail;
		tail->next = newp;
		temp->prev = newp;
		tail = newp;
		return tail;
	}
}

list *delfirst(list *tail)
{
	if (tail == NULL)
		return tail;
	list *temp = tail->next;
	if (temp == tail)
	{
		free(tail);
		tail = NULL; 
		return tail;
	}
	tail->next = temp->next;
	temp->next->prev = tail;
	free(temp);
	return tail;
}

list *dellast(list *tail)
{
	list *temp;
	if (tail = NULL)
		return tail;
	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return tail;
	}
	temp = tail->prev;
	temp->next = tail->next;
	tail->next->prev = temp;
	free(tail);
	tail = temp;
	return tail;
}

/*
void print(list *tail)
{
	if(tail == NULL)
		printf("No element in the list");
	else
	{
		struct list *temp = tail->next;
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
	list *a;
	list *b;
	
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

	
	struct list *tail;
	tail = NULL;
 	tail = addtoempty(34);
	tail = addatend(tail, 45);
	tail = addatend(tail, 56);

	printf("List before Deletion: ");
	print(tail);
	//tail = delfirst(tail);
	tail = delast(tail);
	printf("List after Deletion: ");
	print(tail);
	return (0);
}
*/
