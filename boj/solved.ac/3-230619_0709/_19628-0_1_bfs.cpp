// [21 mins] 틀린 이유: 문제 조건 잘못 이해함 (웜홀은 선택의 문제가 아님)

#include <bits/stdc++.h>

int hole[100], dep[100];
int main()
{
	int N, M, x, y;
	scanf("%d %d", &N, &M), N += M;
	while (N--)
		scanf("%d %d", &x, &y), hole[x] = y;

	std::deque<int> q;
	dep[1] = 1, q.push_back(1);
	while (!q.empty()) {
		int nx, x = q.front(); q.pop_front();
		if ((nx = hole[x]))
			dep[nx] = dep[x], q.push_front(nx);
		else
			for (int i = 1; i <= 6; i++)
				if ((nx = x + i) <= 100 && !dep[nx])
					dep[nx] = dep[x] + 1, q.push_back(nx);
	}
	printf("%d", dep[100] - 1);
}