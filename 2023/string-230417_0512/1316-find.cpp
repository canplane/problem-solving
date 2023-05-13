#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, res;
string s, t;

int main()
{
    cin >> N;

    res = 0;
    while (N--) {
        cin >> s;
        t = s;
        sort(t.begin(), t.end(), [&](char a, char b) -> bool { return s.find(a) < s.find(b); });
        res += (s == t);
    }
    cout << res;
}