using namespace std;
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

template <class T>
struct cmp {
	bool operator()(const T& a, const T& b) const {
		if (a.second != b.second) {
			return b.second < a.second;
		}
		if (a.first.size() != b.first.size()) {
			return b.first.size() < a.first.size();
		}
		return a.first < b.first;
	};
};

map<string, int> dic;
vector<pair<string, int>> v;

char s[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	while (N--) {
		string s;
		cin >> s;
		if (s.size() >= M) {
			dic[s]++;
		}
	}
	for (auto [s, i] : dic) {
		v.push_back({ s, i });
	}
	sort(v.begin(), v.end(), cmp<pair<string, int>>());
	for (auto [s, i] : v) {
		cout << s << '\n';
	}
}