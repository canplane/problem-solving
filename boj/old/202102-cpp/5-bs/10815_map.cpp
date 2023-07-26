/* 
map은 R-B 트리, unordered_map은 hash로 구현
element 개수가 적으면 unordered_map이 유리, 
그러나 많으면 hash bucket의 충돌이 자주 발생하여 성능이 점차 떨어진다.
*/

#include <cstdio>
#include <unordered_map>

std::unordered_map<int, bool> m;

int main() {
    int N, key;
    scanf("%d", &N);
    while (N--)
        scanf("%d", &key), m[key] = true;
    scanf("%d", &N);
    while (N--)
        scanf("%d", &key), printf("%d ", !!m[key]);
}