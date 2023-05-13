#include <iostream>
#include <algorithm>
using namespace std;

int N;
string s, t;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		t = s;
		cout << (next_permutation(s.begin(), s.end()) ? s : t) << endl;
	}
}