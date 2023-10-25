#include "lists.h"

/**
 *insert_nodeint_at_index - inserts a new node at a given position
 *@head: A pointer to the pointer of the head node list
 *@idx: is the index of the list where the new node should be added ,start at 0
 *@n: Integer values to be added to the list
 *Return: Address of the new node or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *current_node, *previous_node, *new_node;
unsigned int index = 0;
if (head == NULL)
{
return (NULL);
}
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;
if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}
current_node = *head;
previous_node = NULL;
while (current_node != NULL && index < idx)
{
previous_node = current_node;
current_node = current_node->next;
index++;
}
if (index == idx)
{
previous_node->next = new_node;
new_node->next = current_node;
return (new_node);
}
else
{
free(new_node);
return (NULL);
}
}
