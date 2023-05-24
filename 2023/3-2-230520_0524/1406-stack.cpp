/* compile option
g++ --std=c++17 foo.c
*/

using namespace std;
#include <iostream>
#include <stack>
#include <cstring>

char s[100001];
int M;
char c;

stack<char> l, r;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	////

	cin >> s;
	for (int i = 0; s[i]; i++)
		l.push(s[i]);
	cin >> M;
	while (M--) {
		// cin은 char라도 공백 문자 가려서 받아준다!
		cin >> c;
		switch (c) {
		case 'P':
			cin >> c;
			l.push(c);
			break;
		case 'L':
			if (l.size())
				r.push(l.top()), l.pop();
			break;
		case 'D':
			if (r.size())
				l.push(r.top()), r.pop();
			break;
		case 'B':
			if (l.size())
				l.pop();
			break;
		}
	}
	while (l.size())
		r.push(l.top()), l.pop();
	while (r.size())
		cout << r.top(), r.pop();
}