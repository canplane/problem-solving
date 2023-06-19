using namespace std;
#include <cstdio>
#include <algorithm>
#include <map>

int A, B;

map<long, unsigned int> visit;
void dfs(long v, unsigned int dep)
{
	if (v > B || (visit[v] && dep >= visit[v]))
		return;
	visit[v] = dep;
	if (v < B)
		dfs(2 * v, dep + 1), dfs(10 * v + 1, dep + 1);
}

int main()
{
	scanf("%d %d", &A, &B);

	visit[B] = -1;
	dfs(A, 1);
	printf("%d", visit[B]);
}