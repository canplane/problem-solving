/*
nth_element, sort 아래와 같이 구현 안 하면 시간 초과된다. 이렇게 짜야 하는 듯
(randomized 안 하거나, nth 대신 sort 써도 통과는 되는데, 원래 짜던 식으로 짜면 안 되더라)
*/

#include    <stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define		SWAP(x, y, t)	((t) = (x), (x) = (y), (y) = (t))

#define		T				int
T A[5000000];
int N, K;

/* 조건문 N번 */
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

int main() {
	srand(time(NULL));
	
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	nth_element(A, A + K - 1, A + N);
	printf("%d", A[K - 1]);
}