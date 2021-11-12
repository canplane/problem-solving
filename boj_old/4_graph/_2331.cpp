#include <cstdio>

int seq[1000000], next[1000000];  // 6 * 9^5 = 354294 < 10^6

int pow(int n, int pow) {
    int ret = 1;
    while (pow--)
        ret *= n;
    return ret;
}

int main() {
    int A, P, u, i;
    scanf("%d %d", &A, &P);
    
    for (u = A, i = 1; !seq[u]; u = next[u]) {
        seq[u] = i++;
        // 복사하지 않으면 u 위치 바뀐다. immutable 주의!
        for (int x = u; x; x /= 10)
            next[u] += pow(x % 10, P);
    }
    printf("%d", seq[u] - 1);
}