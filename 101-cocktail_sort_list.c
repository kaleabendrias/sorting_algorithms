#include "sort.h"

void swap_node(listint_t *p, listint_t *c, listint_t **list)
{
	if (!(p->prev))
	{
		p->next = c->next;
		if (c->next)
			c->next->prev = p;
		c->next = p;
		c->prev = NULL;
		p->prev = c;
		*list = c;
	}
	else
	{
		c->prev->next = c->next;
		if (c->next)
			c->next->prev = c->prev;
		p->prev->next = c;
		c->prev = p->prev;
		p->prev = c;
		c->next = p;
	}
}

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *c, *nextnode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	c = *list;
	do {
		swapped = 0;
		while (c->next)
		{
			nextnode = c->next;
			if (nextnode && c->n > nextnode->n)
			{
				swap_node(c, nextnode, list);
				swapped = 1;
				print_list(*list);
			}
			c = c->next;
		}
		c = c->prev;
		while (c->prev)
		{
			nextnode = c->prev;
			if (nextnode && c->n < nextnode->n)
			{
				swap_node(nextnode, c, lisit);
				swapped = 1;
				print_list(*list);
			}
			c = c->next;
		}
	} while (swapped);
}
