// 시간 초과: 멍청했다. 조합을 일일이 dfs로 구하려 했음.
// 확통 수학처럼 접근하지 않고 단순히 수형도로 구하는 꼴.

using namespace std;
#include <iostream>
#include <map>
#include <vector>

map<string, int> dic;

vector<int> v;
int r;
long combi(int n_i, int r_i, long ncase)
{
	if (r_i == r) {
		return ncase;
	}
	int ret = 0;
	for (int i = n_i; i < v.size(); i++) {
		ret += combi(i + 1, r_i + 1, ncase * v[i]);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		dic.clear();
		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			dic[b]++;
		}

		v.clear();
		for (auto& [s, i] : dic) {
			v.push_back(i);
		}

		long ans = 0;
		for (r = 1; r <= v.size(); r++) {
			ans += combi(0, 0, 1);
		}
		cout << ans << '\n';
	}
}