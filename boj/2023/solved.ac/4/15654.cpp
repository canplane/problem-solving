using namespace std;
#include <cstdio>
#include <algorithm>
#include <vector>

int N, M, A[8];
vector<vector<int>> perms;
void permut(int r_i)
{
	if (r_i == M) {
		vector<int> p;
		for (int i = 0; i < M; i++)
			p.push_back(A[i]);
		perms.push_back(p);
		return;
	}
	for (int i = r_i; i < N; i++) {
		swap(A[r_i], A[i]);
		permut(r_i + 1);
		swap(A[r_i], A[i]);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	permut(0);
	sort(perms.begin(), perms.end());
	for (auto p : perms) {
		for (int e : p)
			printf("%d ", e);
		printf("\n");
	}
}