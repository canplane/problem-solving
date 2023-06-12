/*
	Meet on the Middle (map)

	vector -> two pointers (13528 KB, 160 ms)
	vector -> binary search (13528 KB, 216 ms)
	map (binary search) (42888 KB, 728 ms)
	=> 정렬 + 투 포인터로 하는 것이 좋다.
*/

using namespace std;
#include <cstdio>
#include <map>

int N, S;
int A[40];

map<int, int> sum_l;
long cnt = 0;

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

	dfs(0, N / 2, [](int acc) { sum_l[acc]++; }, 0);
	dfs(N / 2, N, [](int acc) { cnt += sum_l[S - acc]; }, 0);
	printf("%ld", cnt - (S == 0));
}