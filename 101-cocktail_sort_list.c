#include "sort.h"

/**
 * swap_nodes - function to swap two nodes of doubly linked list
 * @list: the doubly linked list
 * @nodeA: the first node
 * @nodeB: the second node
 */
void swap_nodes(listint_t **list, listint_t *nodeA, listint_t *nodeB)
{
	if (nodeA == NULL || nodeB == NULL)
		return;

	if (nodeA->prev != NULL)
		nodeA->prev->next = nodeB;
	if (nodeB->next != NULL)
		nodeB->next->prev = nodeA;

	nodeA->next = nodeB->next;
	nodeB->prev = nodeA->prev;
	nodeA->prev = nodeB;
	nodeB->next = nodeA;

	if (nodeB->prev == NULL)
		*list = nodeB;
}

/**
 * cocktail_sort_list - sorts a doubly linked list using the cocktail
 * sorting algorithm
 * @list: the doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *left, *right;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (left = *list; left->next != NULL; left = left->next)
		{
			right = left->next;
			if (left->n > right->n)
			{
				swap_nodes(list, left, right);
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		for (right = left->prev; right != NULL; right = right->prev)
		{
			left = right->prev;
			if (right->n < left->n)
			{
				swap_nodes(list, left, right);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}
