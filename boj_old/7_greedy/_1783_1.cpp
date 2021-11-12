#include <cstdio>
#define MIN2(x, y) ((x) <= (y) ? (x) : (y))

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int ans;
    if (N == 1)
        ans = 1;
    else if (N == 2)
        ans = MIN2((M + 1)/2, 4);
    else {
        if (M >= 7)
            ans = M - 2;
        else
            ans = MIN2(M, 4);
    }
    printf("%d", ans);
}