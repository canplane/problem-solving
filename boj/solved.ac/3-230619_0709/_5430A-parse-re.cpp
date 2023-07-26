// re가 더 느림

using namespace std;
#include <iostream>
#include <string>
#include <deque>
#include <regex>

void parse(deque<int>& x, string& xs)
{
	regex re(R"(\d+)");
	sregex_iterator rit(xs.begin(), xs.end(), re), rit_end;
	while (rit != rit_end)
		x.push_back(stoi((rit++)->str()));
}
void solve(deque<int>& x, string& p)
{
	int rc = 0;
	for (char c : p) {
		if (c == 'D') {
			if (!x.empty()) {
				if (rc % 2)
					x.pop_back();
				else
					x.pop_front();
			}
			else {
				cout << "error\n";
				return;
			}
		}
		else
			rc++;
	}
	if (rc % 2)
		reverse(x.begin(), x.end());
	cout << "[";
	if (!x.empty()) {
		cout << *x.begin();
		for (auto it = x.begin() + 1; it != x.end(); it++)
			cout << "," << *it;
	}
	cout << "]\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		string p;
		int n;
		string xs;
		
		cin >> p;
		cin >> n;
		cin >> xs;
		
		deque<int> x;
		parse(x, xs);
		solve(x, p);
	}
}