#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

char buf[1000];

int main()
{
    int N;
    scanf("%d", &N);

    vector<pair<int, string>> v(N);
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &v[i].first, buf);
        v[i].second = buf;
    }
    stable_sort(v.begin(), v.end(), [](auto a, auto b) { return a.first < b.first; });
    for (int i = 0; i < N; i++) {
        printf("%d %s\n", v[i].first, v[i].second.c_str());
    }
}