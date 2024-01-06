#include "push_swap.h"

list *tail_find(list **stack)
{
	list *tail;

	if (*stack == NULL)
		return;
	tail = *stack;
	if (tail->next == *stack)
		return (tail);
	while (tail->next != *stack)
		tail = tail->next;
	return (tail);
}

void free_whole_stack(list **stack)
{
	list *aux;
	list *del;

	if (*stack == NULL)
		return;
	aux = (*stack)->next;
	del = null;
	if (aux == *stack)
	{
		free (*stack);
		*stack = NULL;
		return ;		
	}
	while (aux	!= *stack)
	{
		del = aux;
		aux = aux->next;
		free (del);
	}
	free(*stack);
	*stack = NULL;
}
