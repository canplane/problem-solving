#include <cstdio>
#include <queue>

int main()
{
    int N, K, i;
    scanf("%d %d", &N, &K);
    
    std::queue<int> q;
    for (i = 1; i <= N; i++)
        q.push(i);

    printf("<"), i = 0;
    while (q.size() > 1) {
        if (++i == K)  // i = (i + 1) % K는 훨씬 더 느려짐!
            printf("%d, ", q.front()), i = 0;  // 빠지는 쪽이 front!!
        else
            q.push(q.front());
        q.pop();
    }
    printf("%d>", q.front());
}