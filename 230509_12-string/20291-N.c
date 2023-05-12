#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>




/** List */

typedef struct ListNode { void *item; struct ListNode *next; } ListNode;
typedef struct List { ListNode *head, *tail; int size; } List;

#define ListNode__item(node, T) (*(T *)((node)->item))

List *new__List()
{
	List *li;
	li = malloc(sizeof(List)), memset(li, sizeof(List), 0);
	return li;
}

void List__push(List *li, void *item)
{
	li->size++;
	ListNode *node;
	node = malloc(sizeof(ListNode)), node->item = item;
	if (!li->head)
		li->head = li->tail = node;
	else
		li->tail = li->tail->next = node;
}




/** Dictionary */

#define			__DICT__LISTS_SZ 						47

typedef struct DictItem { char *key; void *val; } DictItem;
typedef struct Dict { List *lists[__DICT__LISTS_SZ]; int size; } Dict;

#define			DictItem__key(item)						((item)->key)
#define			DictItem__val(item, T)					(*(T *)((item)->val))

Dict *new__Dict()
{
	Dict *d;
	d = malloc(sizeof(Dict));
	for (int i = 0; i < __DICT__LISTS_SZ; i++)
		d->lists[i] = new__List();
	return d;
}

int __Dict__key_to_idx(char *s)
{
	int ret = 0;
	for (int i = 0; s[i]; i++)		ret += s[i];
	return ret % __DICT__LISTS_SZ;
}

#define Dict__get(d, key, T) (*(T *)__Dict__get(d, key, sizeof(T)))
void *__Dict__get(Dict *d, char *key, int T_sz)
{
	int idx = __Dict__key_to_idx(key);

	List *li = d->lists[idx];
	ListNode *node;
	DictItem *item;
	for (node = li->head; node; node = node->next)
		if (!strcmp(key, (item = node->item)->key))		break;
	if (!node) {
		d->size++;
		item = malloc(sizeof(DictItem));
		item->key = strdup(key);
		item->val = malloc(T_sz), memset(item->val, 0, T_sz);
		List__push(li, item);
	}

	return item->val;
}

DictItem **Dict__items(Dict *d)
{
	DictItem **arr = malloc(d->size * sizeof(void *)), **p;
	p = arr;
	for (int i = 0; i < __DICT__LISTS_SZ; i++)
		for (ListNode *node = d->lists[i]->head; node; node = node->next)
			*p++ = (DictItem *)node->item;
	return arr;
}




/** Main */

#define			sort(begin, end, cmp)					qsort((begin), (end) - (begin), sizeof(*(begin)), (cmp))

int static __cmp(const void *_a, const void *_b)
{
	DictItem *a = *((DictItem **)_a), *b = *((DictItem **)_b);
	return strcmp(DictItem__key(a), DictItem__key(b));
}

char strbuf[101];

int main()
{
	int N;
	scanf("%d", &N);

	Dict *d = new__Dict();
	while (N--) {
		scanf("%s", strbuf);
		char *key = strstr(strbuf, ".") + 1;
		Dict__get(d, key, int) += 1;
	}

	DictItem **items = Dict__items(d);
	sort(items, items + d->size, __cmp);
	for (int i = 0; i < d->size; i++) {
		const DictItem *item = items[i];
		printf("%s %d\n", DictItem__key(item), DictItem__val(item, int));
	}
}