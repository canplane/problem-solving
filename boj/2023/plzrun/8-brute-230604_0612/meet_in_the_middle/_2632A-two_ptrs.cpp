using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

int k;
int A[2000], m;
int B[2000], n;

/* 4 :
	(1, 2, 3, 4), -> 1
	(1, 2, 3), (2, 3, 4), (3, 4, 1), (4, 1, 2), -> n
	(1, 2), (2, 3), (3, 4), (4, 1), -> n
	(1), (2), (3), (4) -> n
*/

vector<int> L, R;

void f(vector<int>& v, int a[], int sz)
{
	int sum[sz];
	sum[0] = a[0];
	for (int i = 1; i < sz; i++)
		sum[i] = sum[i - 1] + a[i];

	v.push_back(0);
	for (int j = 0; j < sz; j++)
		v.push_back(sum[j]);
	for (int i = 0; i < sz - 1; i++) {
		for (int j = (i + 1) % sz; j != i; j = (j + 1) % sz) {
			if (i < j)
				v.push_back(sum[j] - sum[i]);
			else
				v.push_back((sum[sz - 1] - sum[i]) + sum[j]);
		}
	}
}

int main()
{
	scanf("%d", &k);
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &B[i]);

	f(L, A, m), f(R, B, n);
	sort(L.begin(), L.end()), sort(R.begin(), R.end());

	long cnt = 0;
	long i = 0, j = R.size() - 1;
	while (i < L.size() && j >= 0) {
		if (L[i] + R[j] == k) {
			long i_l = i, j_r = j;
			while (i < L.size() && L[i] == L[i_l])	i++;
			while (j >= 0 && R[j] == R[j_r])		j--;
			cnt += (i - i_l) * (j_r - j);
		}
		else {
			if (L[i] + R[j] < k)
				i++;
			else
				j--;
		}
	}
	printf("%ld", cnt);
}