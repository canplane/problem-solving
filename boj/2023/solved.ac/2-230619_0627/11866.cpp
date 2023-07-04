using namespace std;
#include <cstdio>
#include <deque>

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	
	deque<int> q;
	for (int i = 0; i < N; i++) {
		q.push_back(i + 1);
	}
	printf("<");
	int i = 0, x;
	while (q.size() > 1) {
		x = q.front(), q.pop_front();
		i += 1;
		if (i % K == 0) {
			printf("%d, ", x);
		}
		else {
			q.push_back(x);
		}
	}
	printf("%d>", q.front());
}