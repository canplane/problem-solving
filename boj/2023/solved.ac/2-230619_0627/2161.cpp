using namespace std;
#include <cstdio>
#include <deque>

int main()
{
	int N;
	scanf("%d", &N);

	deque<int> q;
	for (int i = 1; i <= N; i++) {
		q.push_back(i);
	}

	printf("%d ", q.front()), q.pop_front();
	while (!q.empty()) {
		q.push_back(q.front()), q.pop_front();
		printf("%d ", q.front()), q.pop_front();
	}
}