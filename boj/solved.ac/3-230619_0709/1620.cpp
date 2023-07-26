using namespace std;
#include <cstdio>
#include <string>
#include <vector>
#include <map>

char query[101], *p;
vector<string> by_num;
map<string, int> by_name;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	by_num.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%s", query);
		by_num[i] = query;
		by_name[query] = i;
	}
	while (M--) {
		scanf("%s", query);
		int x = strtol(query, &p, 10);
		if (query != p)
			printf("%s\n", by_num[x].c_str());
		else
			printf("%d\n", by_name[query]);
	}
}