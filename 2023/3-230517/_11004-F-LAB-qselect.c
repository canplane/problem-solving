#include    <stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define		SWAP(x, y, t)	((t) = (x), (x) = (y), (y) = (t))

#define		T				int
T A[5000000];
int N, K;

/* 시간 초과. 2N번 조건문 */
void nth_element(T *l, T *nth, T *r) {
	T t;
	if (l == r)		return;

	T *pi = l + rand() % (r - l);
	SWAP(*pi, *l, t);

	T *i = l, *j;
	for (j = l + 1; j < r; j++) {
		if (*j <= *l)	++i, SWAP(*j, *i, t);
	}
	SWAP(*l, *i, t);

	if (nth == i)	return;
	if (nth < i)	nth_element(l, nth, i);
	else			nth_element(i + 1, nth, r);
}

int main() {
	srand(time(NULL));
	
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	nth_element(A, A + K - 1, A + N);
	printf("%d", A[K - 1]);
}