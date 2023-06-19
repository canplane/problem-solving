using namespace std;
#include <cstdio>
#include <queue>

priority_queue<int> pq;

int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (!pq.empty())
				x = -pq.top(), pq.pop();
			printf("%d\n", x);
		}
		else {
			pq.push(-x);
		}
	}
}