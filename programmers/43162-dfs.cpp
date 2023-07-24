// 네트워크: https://school.programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>

using namespace std;

int N;
vector<vector<int>> A_NIL, &A = A_NIL;

bool vis[200];
void dfs(int v)
{
	vis[v] = true;
	for (int w = 0; w < N; w++) {
		if (A[v][w] && !vis[w]) {
			dfs(w);
		}
	}
}

int solution(int n, vector<vector<int>> _A) {
	A = _A, N = _A.size();

	int ans = 0;
	for (int v = 0; v < N; v++) {
		if (!vis[v]) {
			++ans, dfs(v);
		}
	}
	return ans;
}