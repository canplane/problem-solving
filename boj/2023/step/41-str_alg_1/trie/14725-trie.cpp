// N-ary 트리 연습하기 매우 유용한 트라이 문제. 자식 리스트를 map/vector 중 무엇으로 두느냐에 따라 시공간 성능을 등가 교환.

using namespace std;
#include <bits/stdc++.h>

struct Trie {
	map<string, Trie *> next;

	Trie *insert(string s) {
		auto [it, b] = next.insert({ s, NULL });
		if (b) {
			it->second = new Trie();
		}
		return it->second;
	}
	void dfs(int level) {
		for (auto [s, child] : next) {
			for (int _ = 0; _ < level; _++)
				printf("--");
			printf("%s\n", s.c_str());

			child->dfs(level + 1), delete child;
		}
	}
};

char s[15];

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
	trie->dfs(0), delete trie;
}