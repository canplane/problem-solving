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

	if (q.size() > 1) {
		q.pop_front();
		while (q.size() > 1) {
			q.push_back(q.front()), q.pop_front();
			q.pop_front();
		}
	}
	printf("%d", q.front());
}