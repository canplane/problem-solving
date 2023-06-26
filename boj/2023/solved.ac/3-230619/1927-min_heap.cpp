using namespace std;
#include <cstdio>
#include <queue>

priority_queue<int> pq;
// priority_queue<int, vector<int>, greater<int>> : min heap

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