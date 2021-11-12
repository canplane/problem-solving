#include <stdio.h>

struct Node {
    int arr[3][3];
};

int main() {
    struct Node node;
    printf("%lu\n", sizeof(node));
    printf("%lu\n", sizeof(node.arr));
}