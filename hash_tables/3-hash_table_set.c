#include "hash_tables.h"

/**
 * update_value - Updates the value of an existing key
 * @node: The node to update
 * @value: The new value
 *
 * Return: 1 on success, 0 on failure
 */
int update_value(hash_node_t *node, const char *value)
{
	char *value_copy = strdup(value);

	if (!value_copy)
		return (0);

	free(node->value);
	node->value = value_copy;

	return (1);
}

/**
 * add_new_node - Creates and inserts a new node at the beginning of the list
 * @head: Pointer to the head of the linked list
 * @key: The key
 * @value: The value
 *
 * Return: 1 on success, 0 on failure
 */
int add_new_node(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *new_node = malloc(sizeof(hash_node_t));

	if (!new_node)
		return (0);

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (!new_node->value)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = *head;
	*head = new_node;

	return (1);
}

/**
 * hash_table_set - Adds or updates a key/value pair in a hash table
 * @ht: The hash table
 * @key: The key
 * @value: The value
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current;

	if (!ht || !key || strlen(key) == 0 || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (update_value(current, value));
		current = current->next;
	}

	return (add_new_node(&ht->array[index], key, value));
}
