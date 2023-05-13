#include <cstdio>
#define ABS(x) ((x) < 0 ? -(x) : (x))

char A[100001], B[100001];

int main()
{
    int N;
    scanf("%d", &N);
    while (N--) {
        int len;
        scanf("%d", &len);
        scanf("%s", A);
        scanf("%s", B);

        int ret = 0;
        int bias = 0;
        for (int i = 0; i < len; i++) {
            int b = A[i] - B[i];
            if (b > 0) {
                bias++;
                if (bias <= 0)  ret++;
            }
            else if (b < 0) {
                bias--;
                if (bias >= 0)   ret++;
            }
        }
        ret += ABS(bias);
        printf("%d\n", ret);
    }
}