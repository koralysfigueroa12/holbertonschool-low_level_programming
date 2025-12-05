#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: pointer to pointer to the head of the list
 * @index: index of the node to delete (starting at 0)
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int i;

    if (!head || !*head)
        return (-1);

    tmp = *head;

    /* delete first node */
    if (index == 0)
    {
        *head = tmp->next;
        if (*head)
            (*head)->prev = NULL;
        free(tmp);
        return (1);
    }

    /* traverse to the node at index */
    for (i = 0; tmp != NULL && i < index; i++)
        tmp = tmp->next;

    if (!tmp)
        return (-1);

    /* fix pointers */
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;

    free(tmp);
    return (1);
}
