using namespace std;
#include <iostream>
#include <map>

map<string, int> dic;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	
	int k = 0, ans = 0;
	while (N--) {
		string s;
		cin >> s;
		if (s == "ENTER") {
			k++;
		}
		else {
			ans += (dic[s] < k);
			dic[s] = k;
		}
	}
	printf("%d", ans);
}