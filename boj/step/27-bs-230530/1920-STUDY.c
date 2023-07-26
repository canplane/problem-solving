#include <stdio.h>
#include <stdlib.h>
typedef enum { false, true } bool;

int N;
int A[100000];


// sort impl (qsort)
void _sort(int l, int r)
{
	if (l >= r) {
		return;
	}

	int pivot = A[l + rand() % (r - l)];
	int i = l - 1, j = r;
	while (true) {
		while (A[++i] < pivot);
		while (A[--j] > pivot);
		if (i < j) {
			int t;
			t = A[i], A[i] = A[j], A[j] = t;
		}
		else {
			break;
		}
	}
	_sort(l, i), _sort(j + 1, r);
}

// binary search impl
bool _binary_search(int l, int r, int x)
{
	while (l < r) {
		int m = l + (r - l) / 2;
		if (x == A[m]) {
			return true;
		}
		else if (x < A[m]) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	return false;
}
int _lower_bound(int l, int r, int x)
{
	while (l < r) {
		int m = l + (r - l) / 2;
		if (x <= A[m]) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	return l;
}
int _upper_bound(int l, int r, int x)
{
	while (l < r) {
		int m = l + (r - l) / 2;
		if (x < A[m]) {
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	return l;
}


// problem
void sol_1(int x)
{
	printf("%d\n", _binary_search(0, N, x));
}
void sol_2(int x)
{
	int l = _lower_bound(0, N, x);
	printf("%d\n", l < N && A[l] == x);
}
void sol_3(int x)
{
	int r = _upper_bound(0, N, x);
	printf("%d\n", r > 0 && A[r - 1] == x);
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	_sort(0, N);

	int M;
	scanf("%d", &M);
	while (M--) {
		int x;
		scanf("%d", &x);

		//sol_1(x);	// binary_search
		sol_2(x);	// lower_bound
		//sol_3(x);	// upper_bound
	}
}