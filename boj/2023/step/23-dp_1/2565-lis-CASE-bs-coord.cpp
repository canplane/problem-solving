// CASE STUDY: if with coordinate compression?

using namespace std;
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

// coordinate compression
void compress_coord(int a[], int n)
{
	pair<int, int> p[n];
	for (int i = 0; i < n; i++) {
		p[i] = { a[i], i };
	}
	sort(p, p + n);
	int j = 0;
	for (int i = 0; i < n; i++) {
		j += (i > 0 && p[i].first != p[i - 1].first);	//
		a[p[i].second] = j++;
	}
}

int N;
int A[100], _from[100], _to[100];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		_from[i] = x, _to[i] = y;
	}
	compress_coord(_from, N), compress_coord(_to, N);
	for (int i = 0; i < N; i++) {
		A[_from[i]] = _to[i];
	}

	vector<int> lis;
	for (int i = 0; i < N; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), A[i]);
		if (it == lis.end()) {
			lis.push_back(A[i]);
		}
		else {
			*it = A[i];
		}
	}
	printf("%ld", N - lis.size());
}