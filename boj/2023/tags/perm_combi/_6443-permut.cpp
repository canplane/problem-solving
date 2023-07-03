using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>

char s[21];
int len;

bool visit[20];
char perm[21];
void dfs(int r_i)
{
	if (r_i == len) {
		printf("%s\n", perm);
		return;
	}

	char pre = 0;
	for (int i = 0; i < len; i++) {
		if (visit[i])
			continue;
		if (s[i] == pre)
			continue;
		pre = s[i];
		visit[i] = true;
		perm[r_i] = s[i], dfs(r_i + 1);
		visit[i] = false;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", s);
		len = strlen(s);
		sort(s, s + len);

		memset(visit, 0, sizeof(visit));
		dfs(0);
	}
}