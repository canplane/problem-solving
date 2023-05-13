#include <cstdio>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> m;

int main()
{
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //

    string s;
    int total = 0;
    while (getline(cin, s)) {
        m[s]++;
        total++;
    }
    for (auto e : m) {
        printf("%s %.4f\n", e.first.c_str(), (double)100 * e.second / total);
    }
}