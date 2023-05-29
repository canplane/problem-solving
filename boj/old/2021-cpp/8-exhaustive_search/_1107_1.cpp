#include <cstdio>
#include <cmath>
#include <algorithm>

bool broken[10];
bool turn(int num) {
    if (!num)
        return broken[0] ? -1 : 1;
    int digits = 0;
    while (num) {
        if (broken[num % 10])
            return -1;
        ++digits, num /= 10;
    }
    return digits;
}


bool can_turn(int num) {
    if (!num)
        return !broken[0];
    while (num) {
        if (broken[num % 10])
            return false;
        num /= 10;
    }
    return true;
}
int digits(int num) {
    if (!num)
        return 1;
    int ret = 0;
    while (num)
        ++ret, num /= 10;
    return ret;
}

int main() {
    int N, M, tmp;
    scanf("%d %d", &N, &M);
    while (M--) {
        scanf("%d", &tmp);
        broken[tmp] = true;
    }
    
    int ans = abs(N - 100);
    for (int i = 0; i < 1000000; i++)
        if (can_turn(i))
            ans = std::min(ans, digits(i) + abs(N - i));
    printf("%d", ans);
}