#include <cstdio>
#include <cstring>

char A[51], B[51];
int lA, lB;

int main()
{
    scanf("%s %s", A, B);
    lA = strlen(A), lB = strlen(B);

    int min_diff = 1e9, diff;
    for (int i = 0; i <= lB - lA; i++) {
        diff = 0;
        for (int j = 0; j < lA; j++) {
            if (B[i + j] - A[j])
                diff++;
        }
        if (diff < min_diff)
            min_diff = diff;
    }
    printf("%d", min_diff);
}