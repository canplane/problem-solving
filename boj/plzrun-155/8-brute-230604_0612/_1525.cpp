using namespace std;
#include <cstdio>
#include <string>
#include <queue>
#include <utility>
#include <set>
#include <algorithm>

int bfs(string x, string y)
{
	set<string> visit;
	
	queue<pair<string, int>> q;
	visit.insert(x), q.push({ x, 0 });
	while (q.size()) {
		auto [v, d] = q.front(); q.pop();
		if (v == y)
			return d;
		
		int blank = v.find('0');
		vector<string> adj;
		if (blank / 3 > 0) {
			string w = v;
			swap(w[blank], w[blank - 3]);
			adj.push_back(w);
		}
		if (blank / 3 < 2) {
			string w = v;
			swap(w[blank], w[blank + 3]);
			adj.push_back(w);
		}
		if (blank % 3 > 0) {
			string w = v;
			swap(w[blank], w[blank - 1]);
			adj.push_back(w);
		}
		if (blank % 3 < 2) {
			string w = v;
			swap(w[blank], w[blank + 1]);
			adj.push_back(w);
		}
		for (string w : adj) {
			if (visit.find(w) == visit.end()) {
				visit.insert(w), q.push({ w, d + 1 });
			}
		}
	}
	return -1;
}

int main()
{
	string s = "";
	int n;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			scanf("%d", &n);
			s += '0' + n;
		}
	}
	printf("%d", bfs(s, "123456780"));
}