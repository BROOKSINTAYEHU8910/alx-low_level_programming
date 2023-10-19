#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * list_len - Counts the number of nodes in a linked list.
 * @h: Pointer to the head of the list.
 * Return: Number of nodes.
 */
size_t list_len(const list_t *h)
{
	int count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}

