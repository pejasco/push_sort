/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuleung <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 21:45:28 by chuleung          #+#    #+#             */
/*   Updated: 2024/01/01 18:48:15 by chuleung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

node *init_stack_a(stack_node **ptr_to_stack, int **arry_of_ints)
{
	int 		i; 
	stact_node	*tail;

	if (arry_of_ints[i] = NULL)
		return (1);
	tail = NULL;
	tail = addtoempty(arry_of_ints[i++][0]);
	*ptr_to
	while (arry_of_ints[i])
	{
		tail = addtoempty(arry_of_ints[i][0]);
		i++;
	}
}

node *stack_in(stack_node **ptr_to_stack, stack_node **tail, int data)
{
	if (*ptr_to_stack = NULL)
	{
		*tail = addatend(*tail, data);
		*ptr_to_stack = *tail;
	}
	else
		*tail = addatend(*tail, data);
	return (*tail);	
}

node *stack_out(stack_node **ptr_to_stack, stack_node **tail)
{
	*tail = delfirst(*tail)
	if (*tail =	NULL)
		{
			free(*ptr_to_stack);
			ptr_to_stack = NULL;
		}
	return (*tail);
}


node* addtoempty(int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;
	return temp;
}

node *addatbeg(struct node *tail, int data)
{
	struct node *newp = addtoempty(data);
	if(tail == NULL)
	{
		return newp;
	}
	else
	{
		newp->prev = tail;
		newp->next = temp;
		temp->prev = newp;
		tail->new = newp;
		return tail;
	}
}

stack_node *addatend(struct node *tail, int data)
{
	struct node *newp;
	struct node *temp;

	newp = NULL;
	temp = NULL;
	struct node* newp = addtoempty(data);
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

struct node *delfirst(struct node  *tail)
{
	if (tail == NULL)
		return tail;
	struct node *temp = tail->next;
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

struct node *dellast(struct node *tail)
{
	struct node *temp;
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




void print(struct node *tail)
{
	if(tail == NULL)
		printf("No element in the list");
	else
	{
		struct node *temp = tail->next;
		do
		{
			printf("%d", temp->data);
			temp = temp->next;
		} while(temp != tail->next);
	}
	printf("\n");
}

int	main()
{
	struct node* tail;

	tail = NULL;
	tail = addtoempty(45);
	tail = addatbeg(tail, 34);
	tail = addatend(tail, 56);
	print(tail);
	return (0);
}

int main()
{
	struct node *tail;

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







void init_stack_node(stack_node **tail_aka_bottom, int value)
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

void insert_beggining(stack_node **tail_aka_bottom, int value)
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
	tail = addtoempty(45);
	tail = addatbeg


}
