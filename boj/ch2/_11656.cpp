#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s[1000];
    int sz, i;
    cin >> s[0];
    sz = s[0].size();
    for (i = 1; i < sz; i++) s[i] = s[0].substr(i);
    sort(s, s + sz);
    for (i = 0; i < sz; i++) cout << s[i] << "\n";
}