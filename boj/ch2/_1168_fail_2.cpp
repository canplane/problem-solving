#include <cstdio>
#define MAXSZ 100000
#define push(x) ( q[back = (back + 1) % MAXSZ] = (x) )
#define pop() ( q[front = (front + 1) % MAXSZ] )

int q[MAXSZ + 1], front, back;

int main()
{
    int N, K, i, j;
    scanf("%d %d", &N, &K);

    for (i = 1; i <= N; i++) push(i);
    
    printf("<");
    for (i = 1; i < N; i++) {
        for (j = 1; j < K; j++) push(pop());
        printf("%d, ", pop());
    }
    printf("%d>", pop());
}