using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>

void parse(deque<int>& x, char *xs)
{
	xs = strtok(xs, "[,]");
	int i = 0;
	while (xs) {
		x.push_back(atoi(xs));
		xs = strtok(NULL, "[,]");
	}
}
void solve(deque<int>& x, char *p)
{
	int rc = 0;
	for (; *p; p++) {
		if (*p == 'R') {
			rc++;
		}
		else {
			if (!x.empty()) {
				if (rc % 2) {
					x.pop_back();
				}
				else {
					x.pop_front();
				}
			}
			else {
				printf("error\n");
				return;
			}
		}
	}
	printf("[");
	if (!x.empty()) {
		if (rc % 2) {
			printf("%d", *x.rbegin());
			for (auto it = next(x.rbegin()); it != x.rend() ; it++) {
				printf(",%d", *it);
			}
		}
		else {
			printf("%d", *x.begin());
			for (auto it = next(x.begin()); it != x.end() ; it++)
				printf(",%d", *it);
		}
	}
	printf("]\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		char p[100001];
		int n;
		char xs[400001];

		scanf("%s", p);
		scanf("%d", &n);
		scanf("%s", xs);

		deque<int> x;
		parse(x, xs);
		solve(x, p);
	}
}