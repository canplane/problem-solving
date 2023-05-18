/*
randomized quicksort
이 코드가 제일 빠름. 수정하지 말 것!
*/

#include	<stdlib.h>
#include	<time.h>
#define		SWAP(x, y, t)	((t) = (x), (x) = (y), (y) = (t))

#define		T				int
void sort(T *l, T *r) {
	T t;
	if (l == r)		return;

	T pi = *(l + rand() % (r - l));
	T *i = l - 1, *j = r;
	while (1) {
		while (*++i < pi);
		while (*--j > pi);
		if (i < j)		SWAP(*i, *j, t);
		else			break;
	}
	// i == j OR i == j + 1
	sort(l, i);
	sort(j + 1, r);
}
void nth_element(T *l, T *nth, T *r) {
	T t;
	if (l == r)		return;

	T pi = *(l + rand() % (r - l));
	T *i = l - 1, *j = r;
	while (1) {
		while (*++i < pi);
		while (*--j > pi);
		if (i < j)		SWAP(*i, *j, t);
		else			break;
	}
	// i == j OR i == j + 1
	if (nth < i)	nth_element(l, nth, i);
	else			nth_element(j + 1, nth, r);
}