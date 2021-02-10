#include <cstdio>

int main() {
    int N;
    long long int fact;  // 10자리에 맨 앞자리 2 이상이면 주의하자! int 범위 초과
    scanf("%d", &N);

    fact = 1;
    while (N > 1) {
        fact *= N;
        N--;
    }
    printf("%lld", fact);
}