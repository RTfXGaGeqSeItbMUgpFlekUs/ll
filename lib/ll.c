#include "ll.h"

#include <stdlib.h>

struct ll *ll_create(void)
{
	struct ll *list;
	list = malloc(SIZEOF_LL);
	list->data = NULL;
	list->next = NULL;
	return list;
}

int ll_append(struct ll *p, void *data)
{
	int i = 0;
	struct ll *list;

	/* Find the element to append to. */
	list = p;
	while (p->next != NULL) {
		p = p->next;
		if (list == p)
			return 1;
		i++;
	}

	/* Switch the next element from NULL to the new item. */
	list = malloc(SIZEOF_LL);
	p->next = list;

	/* Fill in data. */
	list->data = data;
	list->next = NULL;

	return i;
}

int ll_change(struct ll *p, int n, void *data)
{
	struct ll *list = p;
	int i;

	/* Find the element to change. */
	for (i = -1; i < n; i++) {
		list = list->next;
		if (list == NULL)
			return 1;
	}

	list->data = data;

	return 0;
}

int ll_delete(struct ll *p, int n)
{
	struct ll *list = p;
	struct ll *newnext = p;
	int i;

	/* Find the element preceding the element to delete.
	 * We need this so we can change its next element to the element after
	 * the element to delete. */
	for (i = -1; i < n-1; i++) {
		list = list->next;
		if (list == NULL)
			return 1;
	}


	/* We have to store this before freeing it, otherwise Bad Things™ could
	 * happen. */
	newnext = list->next->next;
	free(list->next);
	list->next = newnext;

	return 0;
}
