#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

char buf[100];

int N;
char s[100];
int x;

deque<int> q;

int main()
{
	fgets(buf, 100, stdin), sscanf(buf, "%d", &N);
	while (N--) {
		fgets(buf, 100, stdin), sscanf(buf, "%s %d", s, &x);
		if (!strcmp(s, "push")) {
			q.push_back(x);
		}
		else if (!strcmp(s, "pop")) {
			if (!q.empty()) {
				x = q.front();
				q.pop_front();
			}
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(s, "front")) {
			x = q.empty() ? -1 : q.front();
			printf("%d\n", x);
		}
		else if (!strcmp(s, "back")) {
			x = q.empty() ? -1 : q.back();
			printf("%d\n", x);
		}
		else if (!strcmp(s, "size")) {
			printf("%d\n", q.size());
		}
		else if (!strcmp(s, "empty")) {
			printf("%d\n", q.empty());
		}
	}
}