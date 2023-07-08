// 아무것도 선택하지 않는 경우의 수도 포함하고, 마지막에 아무것도 선택하지 않기만 한 것 하나 빼고

using namespace std;
#include <iostream>
#include <map>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		map<string, int> dic;
		for (int i = 0; i < N; i++) {
			string a, b;
			cin >> a >> b;
			dic[b]++;
		}

		long ans = 1;
		for (auto& [s, i] : dic) {
			ans *= i + 1;
		}
		cout << ans - 1 << '\n';
	}
}