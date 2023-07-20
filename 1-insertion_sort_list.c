#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers using insertion
 * @list: list
 * Return: none
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL, *unsorted = *list, *current, *tmp;

	if (*list == NULL || (*list)->next == NULL)
		return;
	while (unsorted != NULL)
	{
		current = unsorted;
		unsorted = unsorted->next;
		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			tmp = sorted;
			while (tmp->next != NULL && current->n >= tmp->next->n)
				tmp = tmp->next;
			current->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = current;
			tmp->next = current;
			current->prev = tmp;
		}
		print_list(*list);
	}
	*list = sorted;
}
