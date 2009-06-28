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

	list = p;
	while (p->next != NULL) {
		p = p->next;
		if (list == p)
			return 1;
		i++;
	}
	list = malloc(SIZEOF_LL);
	p->next = list;

	list->data = data;
	list->next = NULL;
	return i;
}

int ll_change(struct ll *p, int n, void *data)
{
	struct ll *list = p;
	int i;

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
	int i;

	for (i = -1; i < n-1; i++) {
		list = list->next;
		if (list == NULL)
			return 1;
	}

	free(list->next);
	list->next = list->next->next;

	return 0;
}
