#include <cstdio>
#include <algorithm>

int arr[6] = {1, 4, 2, 1, 2, 4};

int main() {
    std::sort(arr, arr + 6);
    for (int i = 0; i < 6; i++)
        printf("%d ", arr[i]);
}