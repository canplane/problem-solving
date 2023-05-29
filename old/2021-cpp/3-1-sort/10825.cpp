#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

string s[100000];
pair<pair<pair<int, int>, int>, string> p[100000];

int main()
{
    int N, i, kor, eng, math;
    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> s[i] >> kor >> eng >> math;
        p[i] = { { { 100 - kor, eng }, 100 - math }, s[i] };
    }
    sort(p, p + N);
    for (i = 0; i < N; i++)
        cout << p[i].second << "\n";
}