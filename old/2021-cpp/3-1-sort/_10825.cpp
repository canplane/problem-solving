#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int, string> tup[100000];

int main()
{
    ios::sync_with_stdio(false);
    int N, i, a, b, c;
    string s;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> s >> a >> b >> c;
        tup[i] = { 100 - a, b, 100 - c, s };  // make_tuple(100 - a, b, 100 - c, s);
    }
    sort(tup, tup + N);
    for (i = 0; i < N; i++)
        cout << get<3>(tup[i]) << "\n";
}