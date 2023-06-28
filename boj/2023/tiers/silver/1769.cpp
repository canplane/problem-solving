#include <cstdio>

char buf[1000001];
int f()
{
	int cnt = 0;
	for (int i = 0; buf[i]; i++)
		cnt += buf[i] - '0';
	return cnt;
}

int main()
{
	scanf("%s", buf);

	int ans = 0, cnt;
	if (buf[1]) {
		while (true) {
			cnt = f(), ans++;
			if (cnt < 10)
				break;
			sprintf(buf, "%d", cnt);
		}
	}
	else {
		cnt = buf[0] - '0';
	}
	printf("%d\n", ans);
	printf("%s\n", cnt % 3 == 0 ? "YES" : "NO");
}