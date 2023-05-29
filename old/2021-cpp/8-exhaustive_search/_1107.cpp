/* 1시간... */
// num이 0일 때 주의...

#include <cstdio>
#include <cmath>
#include <algorithm>

bool wrong[10];
bool can_jump(int num) {
    if (num == 0) //
        return (wrong[0] == false); //

    while (num) {
        if (wrong[num % 10]) //
            return false; //
        num /= 10;
    }
    return true;
}
int digits(int num) {
    if (num == 0)
        return 1;

    int ret = 0;
    while (num)
        ++ret, num /= 10;
    return ret;
}

int main() {
    int N, M, tmp;
    scanf("%d", &N);
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &tmp);
        wrong[tmp] = true;
    }

    int ans;
    if (N == 100)
        ans = 0;
    else if (can_jump(N))
        ans = std::min(digits(N), abs(N - 100));
    else {
        int l, r;
        if (N > 100)
            l = 100, r = 1000000;
        else
            l = -1, r = 100;

        ans = 0x7fffffff;
        for (int i = N - 1; i > l; i--) {
            if (can_jump(i)) {
                ans = std::min(ans, digits(i) + N - i);
                break;
            }
        }
        for (int i = N + 1; i < r; i++) {
            if (can_jump(i)) {
                ans = std::min(ans, digits(i) + i - N);
                break;
            }
        }
        ans = std::min(ans, abs(N - 100));
    }
    printf("%d", ans);
}