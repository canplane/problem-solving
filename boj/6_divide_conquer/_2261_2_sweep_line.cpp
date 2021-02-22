#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> v;

int main() {
    int N;
    scanf("%d", &N);
    v.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
}