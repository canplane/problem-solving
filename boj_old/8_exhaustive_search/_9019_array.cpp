#include <cstdio>
#include <cstring>

int queue[10000], queue_sz; 

bool visit[10000];
int prev[10000];
char cmd[10000];

void enqueue(int _node, int _prev, char _cmd) {
	if (!visit[_node]) {
		visit[_node] = true, prev[_node] = _prev, cmd[_node] = _cmd;
		queue[queue_sz++] = _node;
	}
}

void postorder(int _node) {
	if (prev[_node] == -1)
		return;
	postorder(prev[_node]);
	putchar(cmd[_node]);
}

int main() {
	int T, A, B;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &A, &B);
		memset(visit, 0, sizeof(visit));

        /* bfs - array */
		queue_sz = 0, enqueue(A, -1, -1);
		for (int i = 0; !visit[B]; i++) {
			int X = queue[i];
			enqueue((2 * X) % 10000, X, 'D');
			enqueue((X + 9999) % 10000, X, 'S');
			enqueue((X % 1000) * 10 + X / 1000, X, 'L');
			enqueue((X % 10) * 1000 + X / 10, X, 'R');
		}
		postorder(B), puts("");
	}
}