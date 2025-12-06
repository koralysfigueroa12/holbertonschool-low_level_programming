#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: pointer to pointer to head of list
 * @index: index of the node to delete (starting at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int len = 0, i;
	dlistint_t *cur;

	if (head == NULL || *head == NULL)
		return (-1);

	/* compute length */
	cur = *head;
	while (cur)
	{
		len++;
		cur = cur->next;
	}

	/* index out of range */
	if (index >= len)
		return (-1);

	/* delete head */
	if (index == 0)
	{
		tmp = *head;
		*head = tmp->next;
		if (*head)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	/* find node at index */
	cur = *head;
	for (i = 0; i < index; i++)
		cur = cur->next;

	/* relink neighbors */
	if (cur->prev)
		cur->prev->next = cur->next;
	if (cur->next)
		cur->next->prev = cur->prev;

	free(cur);
	return (1);
}
