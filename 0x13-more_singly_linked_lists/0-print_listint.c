#include "lists.h"


/**
 * print_listint - prints all the elements of a listint_t list.
 * @h: A pointer to the head the linked list
 * Return: The number of nodes in the linked list
 */

size_t print_listint(const listint_t *h)
{
int count = 0;
const listint_t *ptr = h;
while (ptr != NULL)
{
printf("%d\n", ptr->n);
ptr = ptr->next;
count++;
}
return (count);
}

