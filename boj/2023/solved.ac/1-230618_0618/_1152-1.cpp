using namespace std;
#include <cstdio>
#include <iostream>

int main()
{
	string s;
	getline(cin, s);

	// strip
	if (s.find(" ", 0) == 0) {
		s.replace(0, 1, "");
	}
	// rstrip
	if (s.length() > 0 && s.rfind(" ", string::npos) == s.length() - 1) {
		s.replace(s.length() - 1, 1, "");
	}
	
	// split
	if (s.empty()) {
		cout << 0;
	}
	else {
		int cnt = 1;
		int i = -1;
		while ((i = s.find(" ", i + 1)) != string::npos) {
			cnt += 1;
		}
		cout << cnt;
	}
}