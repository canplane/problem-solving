/*
 * bfs는 queue에 넣을 때 visited set해야 한다. 안 그러면 메모리 초과 터진다.
 * 조금의 비효율성이 큰 차이를 만들어서 시간/메모리 초과를 낼 수 있다. 그래서 이 문제 푸는 데 3시간이나 걸렸다.
 * STL queue 자체가 무거워서, stack도 쓴다든가 조금만 뭘 더 추가해도 시간 초과가 나는 듯 하다.
 * 왜인지는 모르겠으나 오히려 이 코드처럼 굳이 string을 쓰는 것만 잘 작동하는 것으로 보임.
 * 아니면 그냥 참고 코드처럼 queue를 쓰지 말자.
 */

#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <string>
using namespace std;

bool visit[10000];

int main() {
	int T, A, B;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &A, &B);
		memset(visit, 0, sizeof(visit));

		/* bfs - STL queue */
		queue<pair<int, string>> q;
		q.push({ A, "" });
		while (!q.empty()) {
			auto [X, s] = q.front();
			q.pop();

			if (X == B) {
				printf("%s\n", s.c_str());
				goto outer;
			}
            
		int Y;
		if (!visit[Y = (2 * X) % 10000])
			visit[Y] = true, q.push({ Y, s + "D" });
		if (!visit[Y = (X + 9999) % 10000])
			visit[Y] = true, q.push({ Y, s + "S" });
		if (!visit[Y = (X % 1000) * 10 + X / 1000])
			visit[Y] = true, q.push({ Y, s + "L" });
		if (!visit[Y = (X % 10) * 1000 + X / 10])
			visit[Y] = true, q.push({ Y, s + "R" });
		}
		outer:;
	}
}