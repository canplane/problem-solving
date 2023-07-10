/*
	Meet in the Middle (vector -> two pointers)

	vector -> two pointers (13528 KB, 160 ms)
	vector -> binary search (13528 KB, 216 ms)
	map (binary search) (42888 KB, 728 ms)
	=> 정렬 + 투 포인터로 하는 것이 좋다.
*/

using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

int N, S;
int A[40];

vector<int> sum_l, sum_r;

void dfs(int l, int r, void (*callback)(int), int acc=0)
{
	callback(acc);
	for (; l < r; l++)
		dfs(l + 1, r, callback, acc + A[l]);
}

int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	dfs(0, N / 2, [](int acc) { sum_l.push_back(acc); }, 0);
	dfs(N / 2, N, [](int acc) { sum_r.push_back(acc); }, 0);
	sort(sum_l.begin(), sum_l.end());
	sort(sum_r.begin(), sum_r.end());

	long cnt = 0;
	long i = 0, j = sum_r.size() - 1;
	while (i < sum_l.size() && j >= 0) {
		if (sum_l[i] + sum_r[j] == S) {
			long i_l = i, j_r = j;
			while (i < sum_l.size() && sum_l[i] == sum_l[i_l])
				i++;
			while (j >= 0 && sum_r[j] == sum_r[j_r])
				j--;
			cnt += (i - i_l) * (j_r - j);
		}
		else {
			if (sum_l[i] + sum_r[j] < S)
				i++;
			else
				j--;
		}
	}
	printf("%ld", cnt - (S == 0));
}