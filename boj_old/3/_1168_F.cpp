#include <cstdio>
#include <vector>

int main()
{
    int N, K, i;
    scanf("%d %d", &N, &K);
    std::vector<int> v(N);

    for (i = 0; i < N; i++) v[i] = i + 1;

    i = K - 1;
    printf("<");
    while (true) {
        if (N == 1) {
            printf("%d", v[i]);
            break;
        }
        printf("%d, ", v[i]);
        v.erase(v.begin() + i);
        i = ((i - 1) + K) % --N;
    }
    printf(">");
}