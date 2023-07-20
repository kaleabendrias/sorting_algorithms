#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers using insertion
 * @list: list
 * Return: none
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	int x;

	if (list == NULL || !list)
		return;
	temp = *list;
	while (temp)
	{
		while (temp)
		{
			if (temp->next)
			{
				if (temp->n > temp->next->n)
				{
					x = temp->n;
					*(int *)&temp->n = temp->next->n;
					*(int *)&temp->next->n = x;
					temp = *list;
					print_list(*list);
					break;
				}
			}
			temp = temp->next;
		}
	}
}
