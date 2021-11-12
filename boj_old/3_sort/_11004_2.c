#include <stdio.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int _qpart(int a[], int l, int r)
{
    int i = l + 1, j = r;
    int tmp;
    if (l < r) {
        SWAP(a[l], a[(l + r) / 2], tmp);
        while (1) {
            while (i < r && a[i] <= a[l]) i++;
            while (a[j] > a[l]) j--;
            if (i < j) SWAP(a[i], a[j], tmp);
            else break;
        }
        SWAP(a[l], a[j], tmp);
    }
    return j;
}
int qselect(int a[], int l, int r, int k)
{
    int j = _qpart(a, l, r);
    if (k < j) return qselect(a, l, j - 1, k);
    if (k > j) return qselect(a, j + 1, r, k);
    return a[j];
}

int data[5000000];

int main()
{
    int N, K, i;
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) scanf("%d", &data[i]);
    printf("%d", qselect(data, 0, N - 1, K - 1));
}