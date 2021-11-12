#include <cstdio>

int data[500000], N;
long long cnt = 0;  // big integer 주의...

void merge(int dst[], int src[], int l, int mid, int r) {
    int k = l, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (src[i] <= src[j])
            dst[k++] = src[i++];
        else {
            cnt += j - k;  // 오른쪽에 있던 것이 왼쪽으로 이동하는 총 횟수가 총 swap 횟수가 된다!
            dst[k++] = src[j++];
        }
    }
    while (i <= mid)
        dst[k++] = src[i++];
    while (j <= r)
        dst[k++] = src[j++];
}

void mergepass(int dst[], int src[], int size, int s) {
    int i;
    for (i = 0; i + 2*s - 1 < size; i += 2*s)
        merge(dst, src, i, i + s - 1, i + 2*s - 1);
    merge(dst, src, i, ((i + s <= size) ? i + s : size) - 1, size - 1);
}

void mergesort(int a[], int size) {
    int extra[size];
    int s = 1;
    while (s < size) {
        mergepass(extra, a, size, s);
        s *= 2;
        mergepass(a, extra, size, s);
        s *= 2;
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &data[i]);
    mergesort(data, N);
    printf("%lld", cnt);
}