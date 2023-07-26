/* [parsing]
오래 걸림: 파싱 방법이 익숙치 않아서
틀린 이유: char xs[] 사이즈 작게 설정해서 segfault
*/

using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>

void parse(deque<int>& x, char *xs)
{
	int len = strlen(xs);
	xs[0] = xs[len - 1] = ' ';
	for (char *p = xs - 1; (p = strstr(p + 1, ",")); ) {
		*p = ' ';
	}
	FILE *fp = fmemopen(xs, len, "r");
	int d;
	while (fscanf(fp, "%d", &d) == 1) {
		x.push_back(d);
	}
	fclose(fp);
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