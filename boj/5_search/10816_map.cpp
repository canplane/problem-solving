/* map은 시간 초과 발생했다. R-B 트리라서 그런 듯 */

#include <cstdio>
#include <unordered_map>

std::unordered_map<int, int> m;

int main() {
    int N, key;
    scanf("%d", &N);
    while (N--)
        scanf("%d", &key), ++m[key];
    scanf("%d", &N);
    while (N--)
        scanf("%d", &key), printf("%d ", m[key]);
}