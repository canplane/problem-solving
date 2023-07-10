using namespace std;
#include <iostream>
#include <set>

set<string> dic;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	
	int ans = 0;
	while (N--) {
		string s;
		cin >> s;
		if (s == "ENTER") {
			dic.clear();
		}
		else {
			auto [it, b] = dic.insert(s);
			if (b) {
				ans++;
			}
		}
	}
	printf("%d", ans);
}