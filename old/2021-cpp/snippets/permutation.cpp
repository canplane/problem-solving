// bool next_permutation(v.begin(), v.end()); : 있을 때 true
// anagram

#include <cstdio>
#include <algorithm>
using namespace std;

int num[8], N;

void dfs(int idx) {
    if (idx == N) {
        for (int i = 0; i < N; i++)
            printf("%d ", num[i]);
        printf("\n");
    }
    for (int i = idx; i < N; i++) {
        swap(num[idx], num[i]);
        dfs(idx + 1);
        swap(num[idx], num[i]); 
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    printf("\n");
    dfs(0);
}