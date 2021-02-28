#include <stdio.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int qpart(int a[], int l, int r)
{
    int i, j;
    int tmp;
    i = l + 1, j = r;
    if (l < r) {
        SWAP(a[l], a[(l + r) / 2], tmp);
            while (1) {
            while (a[i] <= a[l] && i < r) i++;
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
    int pivot = qpart(a, l, r);
    if (k < pivot) return qselect(a, l, pivot - 1, k);
    if (k > pivot) return qselect(a, pivot + 1, r, k);
    return a[k];
}

#define MAX_N 5000000
int data[MAX_N];

int main()
{
    int N, K, i;
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++) scanf("%d", &data[i]);
    printf("%d\n", qselect(data, 0, N - 1, K - 1));
}