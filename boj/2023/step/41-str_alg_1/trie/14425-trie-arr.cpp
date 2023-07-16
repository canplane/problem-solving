using namespace std;
#include <cstdio>
#include <string>
#include <map>

struct Trie {
	bool end;
	Trie *next[26];

	void insert(char *s) {
		if (!*s) {
			end = true;
			return;
		}

		if (!next[*s - 'a']) {
			next[*s - 'a'] = new Trie();
		}
		next[*s - 'a']->insert(s + 1);
	}
	bool find(char *s)
	{
		if (!*s) {
			return end;
		}

		if (!next[*s - 'a']) {
			return false;
		}
		return next[*s - 'a']->find(s + 1);
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