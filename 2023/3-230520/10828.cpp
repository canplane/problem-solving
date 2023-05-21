#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
 그냥 stringstream .str(buf)로 리셋하려고 하면 제대로 되지 않는다.
 1. stringstream(buf) >> s >> x;
 2. ss.clear(), ss.str(buf); (clear() to reset eof flags)
*/

string buf;

int N;
int stack[100000], sz;

string s;
int x;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	getline(cin, buf), stringstream(buf) >> N;
	while (N--) {
		getline(cin, buf), stringstream(buf) >> s >> x;
		if (s == "push") {
			stack[sz++] = x;
		}
		else if (s == "pop") {
			x = sz ? stack[--sz] : -1;
			cout << x << "\n";
		}
		else if (s == "top") {
			x = sz ? stack[sz - 1] : -1;
			cout << x << "\n";
		}
		else if (s == "size") {
			cout << sz << "\n";
		}
		else if (s == "empty") {
			cout << !sz << "\n";
		}
		else {
			cout << "???\n";
		}
	}
}