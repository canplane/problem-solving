#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int N, i;
    stack<char> l, r;  // stack이 생각보다 빠르다! 따로 구현할 필요 없는 듯.
    string s;
    char c;
    
    cin >> s;
    for (i = 0; i < s.size(); i++) l.push(s[i]);
    cin >> N;
    while (N--) {
        cin >> c;
        switch (c) {
        case 'L':
            if (l.size()) r.push(l.top()), l.pop();
            break;
        case 'D':
            if (r.size()) l.push(r.top()), r.pop();
            break;
        case 'B':
            if (l.size()) l.pop();
            break;
        case 'P':
            cin >> c;
            l.push(c);
            break;
        }
    }
    while (l.size()) {
        r.push(l.top()), l.pop();
    }
    while (r.size()) cout << r.top(), r.pop();
}