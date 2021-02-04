#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    string_view sv[1000];
    cin >> s;
    for (int i = 0; i < s.size(); i++) sv[i] = s.c_str() + i;  // substr(i)로 하면 오류! 임시 객체라 그런 듯?
    sort(sv, sv + s.size());
    for (int i = 0; i < s.size(); i++) cout << sv[i] << "\n";
}