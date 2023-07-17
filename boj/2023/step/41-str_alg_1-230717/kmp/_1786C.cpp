using namespace std;
#include <bits/stdc++.h>

int pi[1 << 20];	// failure array: as of size, not indices (former = latter + 1)
void kmp(vector<int> &pos, string &s, string &pattern)
{
	// get pi (failure function)
	for (int i = 1, j = 0; i < pattern.size(); i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j];
		pi[i + 1] = (pattern[i] == pattern[j]) ? ++j : 0;
	}

	// compare the pattern with a test string
	for (int i = 0, j = 0; i < s.size(); i++) {
		while (j > 0 && s[i] != pattern[j])
			j = pi[j];
		if (s[i] == pattern[j]) {
			if (j + 1 == pattern.size())
				pos.push_back(i - j), j = pi[j + 1];
			else
				j++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s, t;
	getline(cin, s), getline(cin, t);

	vector<int> pos;
	kmp(pos, s, t);

	cout << pos.size() << "\n";
	for (int i : pos)
		cout << (i + 1) << " ";
}