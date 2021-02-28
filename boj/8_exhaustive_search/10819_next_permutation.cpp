#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);

    int ans = 0;
    sort(v.begin(), v.end());
    do {
        int sum = 0;
        for (int i = 1; i < N; i++)
            sum += abs(v[i - 1] - v[i]);
        ans = max(ans, sum);
    } while (next_permutation(v.begin(), v.end()));
    printf("%d", ans);
}