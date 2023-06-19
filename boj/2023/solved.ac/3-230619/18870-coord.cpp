// coordinate compression (좌표 압축)

using namespace std;
#include <cstdio>
#include <algorithm>
#include <utility>

int N, A[1000000];

template <class T>
void compress_coord(T arr[], int n)
{
	pair<T, int> p[n];
	for (int i = 0; i < n; i++) {
		p[i] = { arr[i], i };
	}
	sort(p, p + n);
	int j = 0;
	for (int i = 0; i < n; i++) {
		j += (i > 0 && p[i].first != p[i - 1].first);	//
		arr[p[i].second] = j;
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	compress_coord(A, N);

	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
}