#include "lists.h"

/**
 *sum_listint - Returns the sum of all the data (n) of a listint_t linked list
 *@head: A pointer to head of the node list
 *Return: returns sum of the data in a list or 0 if the list is empty
 */

int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *ptr = head;

while (ptr != NULL)
{
sum += ptr->n;
ptr = ptr->next;
}
return (sum);


}
