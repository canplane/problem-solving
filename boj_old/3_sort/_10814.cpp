#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

char names[100000][101];
pair<pair<int, int>, char *> p[100000];

int main()
{
    int N, i, age;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d %s", &age, names[i]);
        p[i] = { { age, i }, names[i] };  // 이렇게 초기화 사용 가능
    }
    sort(p, p + N);  // pair는 첫 번째 인자 먼저 비교하므로 dfs처럼 생각!
    for (i = 0; i < N; i++)
        printf("%d %s\n", p[i].first.first, p[i].second);
}
