// [31 mins]

using namespace std;
#include <bits/stdc++.h>

struct Trie {
	map<char, Trie *> next;
	bool end;

	void insert(char *s) {
		if (!*s) {
			end = true;
			return;
		}

		auto [it, b] = next.insert({ *s, NULL });
		if (b) {
			it->second = new Trie();
		}
		(it->second)->insert(s + 1);
	}
	int length(int level, Trie *root) {
		if (next.size() == 0) {
			return level;
		}

		int ret = end ? level : 0;
		bool inc = (this == root) || (end || next.size() > 1);
		for (auto [c, child] : next) {
			ret += child->length(level + inc, root);
			delete child;
		}
		return ret;
	}
};

char s[81];
void sol(int N)
{
	Trie *trie = new Trie();
	for (int _ = 0; _ < N; _++) {
		scanf("%s", s);
		trie->insert(s);
	}
	printf("%.2lf\n", (double)trie->length(0, trie) / N);
	delete trie;
}
int main()
{
	int N;
	while (scanf("%d", &N) == 1) {
		sol(N);
	}
}