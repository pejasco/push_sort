/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:45:28 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/02 18:04:50 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

list  *init_stack_a(list **ptr_to_stack, int **arry_of_ints)
{
	int 		i; 
	list	*tail;

	i = 0;
	if (arry_of_ints[i] = NULL)
		return (1);
	tail = NULL;
	tail = append(tail, arry_of_ints[i++]);
	*ptr_to_stack = tail;
	while (arry_of_ints[i])
	{
		tail = append(tail, arry_of_ints[i][0]);
		i++;
	}
}

list *stack_in(list **ptr_to_stack, list **tail, int data)
{
	if (*ptr_to_stack = NULL)
	{
		*tail = push(*tail, data);
		*ptr_to_stack = *tail;
	}
	else
		*tail = append(*tail, data);
	return (*tail);	
}

list *stack_out(list **ptr_to_stack, list **tail)
{
	*tail = pop(*tail)
	if (*tail =	NULL)
		{
			free(*ptr_to_stack);
			ptr_to_stack = NULL;
		}
	return (*tail);
}

list *addtoempty(int data)
{
	list *temp = malloc(sizeof(list));
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;
	return temp;
}

list *push(list *tail, int data)
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

list *append(list *tail, int data)
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

list *pop(list *tail)
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

list *poplast(list *tail)
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

