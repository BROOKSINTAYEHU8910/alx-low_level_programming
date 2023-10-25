#include "lists.h"

/**
 *delete_nodeint_at_index - Deletes the node at index specifief on the  list
 *@head: A pointer to the pointer of head node list
 *@index:Is the index of the node that should be deleted
 *Return: If succeeded 1 if not -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{

listint_t *ptr, *current_node;
unsigned int i;
if (*head == NULL)
{
return (-1);
}
if (index == 0)
{
ptr = *head;
*head = (*head)->next;
free(ptr);
return (1);
}
current_node = *head;

for (i = 0; i < index - 1; i++)
{
if (current_node == NULL)
{
return (-1);
}
current_node = current_node->next;
}

if (current_node == NULL || current_node->next == NULL)
{
return (-1);
}
ptr = current_node->next;
current_node->next = ptr->next;
free(ptr);
return (1);

}
