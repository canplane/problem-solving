#include <cstdio>

void foo() {
    int arr[10]{};  // = {} 이렇게 하면 0 또는 false로 초기화된다. 기본값이 그냥 0 지정인 것. 1로 기본 지정은 안 됨.
    // { 0, }는 틀린 것. { 1, }는 그냥 { 1 }이랑 같음. 그러니 { false }로 쓸 필요도 없다.
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    for (int i = 0; i < 10; i++)
        arr[i] = i + 1;
}

int main() {
    foo();
    foo();
}