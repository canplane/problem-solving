#include <cstdio>

char A[100001], B[100001];

int main()
{
    int N;
    scanf("%d", &N);
    while (N--) {
        int len;
        scanf("%d", &len);
        scanf("%s %s", A, B);
        int inc = 0, dec = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] - B[i] > 0)
                inc++;
            else if (A[i] - B[i] < 0)
                dec++;
        }
        printf("%d\n", inc > dec ? inc : dec);
    }
}