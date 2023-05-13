#include <cstdio>

char s[51], res[51];
int cnt[50][128], dist;

const char C[] = { 'A', 'C', 'G', 'T' };

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for (int _ = 0; _ < N; _++) {
        scanf("%s", s);
        for (int i = 0; i < M; i++) {
            char c = s[i];
            cnt[i][c]++;
        }
    }

    for (int i = 0; i < M; i++) {
        char max_c = 'A';
        for (char c : C) {
            if (cnt[i][c] > cnt[i][max_c])  max_c = c;
        }
        res[i] = max_c;
        for (char c : C) {
            if (c != max_c)
                dist += cnt[i][c];
        }
    }
    
    printf("%s\n%d", res, dist);
}