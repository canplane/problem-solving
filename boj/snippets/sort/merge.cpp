#include <cstdio>

void merge(int dst[], int src[], int l, int mid, int r) {
    int k = l, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        dst[k++] = (src[i] <= src[j]) ? src[i++] : src[j++];
    while (i <= mid)
        dst[k++] = src[i++];
    while (j <= r)
        dst[k++] = src[j++];
}

#define min(x, y) ((x) <= (y) ? (x) : (y))
void mergepass(int dst[], int src[], int size, int s) {
    int i;
    for (i = 0; i + 2*s - 1 < size; i += 2*s)
        merge(dst, src, i, i + s - 1, i + 2*s - 1);
    merge(dst, src, i, min(i + s, size) - 1, size - 1);
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

#define len(x) (sizeof(x) / sizeof((x)[0]))
int main() {
    int data[] = { 1, 26, 5, 37, 1, 61, 26, 11, 59, 59, 15, 48, 26, 5, 19, 11, 39 };
    mergesort(data, len(data));
    for (int i = 0; i < len(data); i++)
        printf("%d ", data[i]);
}