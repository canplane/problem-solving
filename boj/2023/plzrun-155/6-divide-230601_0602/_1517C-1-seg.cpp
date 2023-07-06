using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

int A[500000];

// 세그먼트 트리 (구간 합)
int seg[2000001];
long seg_query(int l, int r, int i, int from, int to)
{
	if (r <= from || to <= l)
		return 0;
	if (from <= l && r <= to)
		return seg[i];
	
	int m = (l + r) / 2;
	return seg_query(l, m, 2 * i, from, to) + seg_query(m, r, 2 * i + 1, from, to);
}
int seg_update(int l, int r, int i, int k)
{
	seg[i] += 1;
	if (l + 1 == r)
		return seg[i];
	
	int m = (l + r) / 2;
	if (k < m)
		return seg_update(l, m, 2 * i, k);
	else
		return seg_update(m, r, 2 * i + 1, k);
}


// 좌표 압축: { 1, 1, 10, 5, 3 } -> { 0, 1, 4, 3, 2 }
// 최댓값은 (배열 사이즈 - 1) 보장
template <class T>
void convert_coord(T arr[], int n)
{
	vector<pair<T, int>> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = { arr[i], i };
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		arr[v[i].second] = i;
	}
}


int main()
{
	
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	// 좌표 압축
	convert_coord(A, N);

	// 앞에 더 큰 수 있으면 그 개수 더하기
	long ans = 0;
	for (int i = 0; i < N; i++) {
		ans += seg_query(0, N, 1, A[i] + 1, N);
		seg_update(0, N, 1, A[i]);
	}
	printf("%ld", ans);
}