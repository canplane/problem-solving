// vector를 이렇게 구현할 수 있음. (메모리는 적은데, 시간이 더 오래 걸릴 듯)
// 단, 이 문제는 사전 순으로 앞서야 하므로 정렬이 필요.

using namespace std;
#include <bits/stdc++.h>

char s[15];

struct Trie {
	vector<pair<string, Trie *>> next;

	Trie *insert(string s) {
		for (auto [_s, child] : next) {
			if (_s == s) {
				return child;
			}
		}
		Trie *child = new Trie();
		next.push_back({ s, child });
		return child;
	}
	void dfs(int level) {
		sort(next.begin(), next.end());
		for (auto [s, child] : next) {
			for (int _ = 0; _ < level; _++)
				printf("--");
			printf("%s\n", s.c_str());
			child->dfs(level + 1);
		}
	}
};

int main()
{
	int N;
	scanf("%d", &N);

	Trie *trie = new Trie(), *p;
	while (N--) {
		int K;
		scanf("%d", &K);
		
		p = trie;
		while (K--)
			scanf("%s", s), p = p->insert(s);
	}
	trie->dfs(0);
}