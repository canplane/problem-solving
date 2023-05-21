#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;

char cmd[100];
int x;

deque<int> deq;

int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "push_back")) {
			scanf("%d", &x);
			deq.push_back(x);
		}
		else if (!strcmp(cmd, "push_front")) {
			scanf("%d", &x);
			deq.push_front(x);
		}
		else if (!strcmp(cmd, "pop_front")) {
			if (!deq.empty())
				x = deq.front(), deq.pop_front();
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(cmd, "pop_back")) {
			if (!deq.empty())
				x = deq.back(), deq.pop_back();
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(cmd, "front")) {
			if (!deq.empty())
				x = deq.front();
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(cmd, "back")) {
			if (!deq.empty())
				x = deq.back();
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", deq.size());
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", deq.empty());
		}
	}
}