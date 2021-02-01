#include <iostream>
#include <algorithm>
#include <utility>
#define MAX_N 100000

using namespace std;

pair<int, int> p[MAX_N];

int main()
{
    int N, i;
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + N, less<>());
    for (i = 0; i < N; i++)
        cout << p[i].first << " " << p[i].second << "\n";
}