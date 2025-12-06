#include "lists.h"
#include <stdlib.h>

/**
 * delete_head - deletes the head node
 * @head: pointer to pointer to head
 *
 * Return: 1 if succeeded
 */
static int delete_head(dlistint_t **head)
{
    dlistint_t *tmp = *head;

    *head = tmp->next;
    if (*head)
        (*head)->prev = NULL;

    free(tmp);
    return (1);
}

/**
 * delete_dnodeint_at_index - deletes node at index of a dlistint_t list
 * @head: pointer to pointer to head of list
 * @index: index of the node to delete
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *cur;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    if (index == 0)
        return (delete_head(head));

    cur = *head;
    for (i = 0; cur && i < index; i++)
        cur = cur->next;

    if (cur == NULL)
        return (-1);

    if (cur->prev)
        cur->prev->next = cur->next;

    if (cur->next)
        cur->next->prev = cur->prev;

    free(cur);
    return (1);
}
