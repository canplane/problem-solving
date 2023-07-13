// 문자열의 길이가 짧으므로 map보다 unordered_map이 더 효율적 (문자열 비교 연산 vs 전체 길이 뭉개기)

using namespace std;
#include <iostream>
#include <unordered_map>
#include <utility>

unordered_map<string, pair<string, int>> dj;
string dj_find(string a)
{
	dj.insert({ a, { a, 1 } });

	string r = a;
	while (dj[r].first != r) {
		r = dj[r].first;
	}
	// 최적화 안 해주면 시간 초과
	string t;
	while (dj[a].first != a) {
		t = dj[a].first, dj[a].first = r, a = t;
	}
	return r;
}
void dj_union(string a, string b)
{
	string ra = dj_find(a), rb = dj_find(b);
	if (ra != rb) {
		dj[rb].first = ra;
		dj[ra].second += dj[rb].second;
	}
	cout << dj[ra].second << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int F;
		cin >> F;

		dj.clear();
		while (F--) {
			string a, b;
			cin >> a >> b;
			dj_union(a, b);
		}
	}
}