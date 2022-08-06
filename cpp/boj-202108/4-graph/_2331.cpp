#include <cstdio>
#include <cmath>

int A, P;
int next[1000001], seq[1000001];

int main() {
    scanf("%d %d", &A, &P);
    for (int i = 1; ; i++) {
        seq[A] = i;

        int nextA = 0;
        for (int x = A; x; x /= 10) {
            nextA += pow(x % 10, P);
        }
        next[A] = nextA, A = nextA;
        
        if (next[A]) {
            printf("%d", seq[A] - 1);
            break;
        }
    }
}