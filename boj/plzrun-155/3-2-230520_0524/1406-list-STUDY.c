#ifndef			__LIST__H
#define			__LIST__H



#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>




typedef struct ListNode { void *item; struct ListNode *prev, *next; } ListNode;
typedef struct List { int size; ListNode *head, *tail; } List;

#define			ListNode__item(node, T)					((T)((node)->item))




ListNode *__new__ListNode(ListNode *prev, ListNode *next, void *item)
{
	ListNode *node = malloc(sizeof(ListNode));
	node->item = item;
	node->prev = prev, node->next = next;
	return node;
}




List *new__List()
{
	ListNode *node = __new__ListNode(NULL, NULL, NULL);
	
	List *li = malloc(sizeof(List));
	li->size = 0;
	li->head = li->tail = node;

	return li;
}
void delete__List(List *li, int _free_item)
{
	ListNode *node, *tmp;
	for (node = li->head; node != li->tail; node = tmp) {
		tmp = node->next;
		if (_free_item)		free(node->item);
		free(node);
	}
	free(li->tail);
	free(li);
}




#define			List__insert(li, next, item)			__List__insert((li), (next), (void *)(item))
ListNode *__List__insert(List *li, ListNode *next, void *item)
{
	ListNode *prev = next->prev;

	li->size++;
	ListNode *node = __new__ListNode(prev, next, item);

	if (prev)
		prev->next = node;
	else
		li->head = node;
	next->prev = node;
	return node;
}
ListNode *List__erase(List *li, ListNode *node, int _free_item)
{
	if (node == li->tail) {
		fprintf(stderr, "Out of bound\n");
		exit(1);
	}

	ListNode *prev = node->prev, *next = node->next;

	li->size--;
	if (_free_item)		free(node->item);
	free(node);

	if (prev)
		prev->next = next;
	else
		li->head = next;
	next->prev = prev;
	return next;
}




#endif




char *new__Char(char c) { char *C = malloc(sizeof(char)); *C = c; return C; }

char s[100001];

int main()
{
	int i;
	char *c;

	List *li = new__List();
	
	scanf("%s", s);
	for (i = 0; s[i]; i++) {
		List__insert(li, li->tail, new__Char(s[i]));
	}

	int N;
	scanf("%d", &N);

	ListNode *it = li->tail;
	while (N--) {
		scanf("%s", s);
		switch (s[0]) {
		case 'P':
			scanf("%s", s);
			List__insert(li, it, new__Char(s[0]));
			break;
		case 'L':
			if (it != li->head)		it = it->prev;
			break;
		case 'D':
			if (it != li->tail)		it = it->next;
			break;
		case 'B':
			if (it != li->head)		it = List__erase(li, it->prev, 1);
			break;
		}
	}

	for (it = li->head; it != li->tail; it = it->next)
		printf("%c", *ListNode__item(it, char *));
	
	delete__List(li, 1);
}