#include <iostream>
#include <string>
using namespace std;

string s, key;
int N, ret;

int main()
{
	cin >> key >> N;
	while (N--) {
		cin >> s;
		s += s.substr(0, key.length() - 1);
		ret += (s.find(key) != string::npos);
	}
	cout << ret;
}