using namespace std;
#include <cstdio>
#include <string>
#include <map>

struct Trie {
	bool end;
	map<char, Trie *> next;

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
	bool find(char *s)
	{
		if (!*s) {
			return end;
		}

		auto it = next.find(*s);
		if (it == next.end()) {
			return false;
		}
		return (it->second)->find(s + 1);
	}
};

char s[501];

int main()
{
	Trie *trie = new Trie();

	int N, M;
	scanf("%d %d", &N, &M);
	while (N--) {
		scanf("%s", s);
		trie->insert(s);
	}

	int ans = 0;
	while (M--) {
		scanf("%s", s);
		ans += !!trie->find(s);
	}
	printf("%d", ans);
}