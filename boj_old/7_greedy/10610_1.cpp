// 그냥 digit별로 카운트해서 높은 순서대로 빼면 된다!

#include <cstdio>

int main() {
    char N[100001];
    scanf("%s", N);

    int cnt[10] = {}, sum_digits = 0;
    for (int i = 0; N[i]; i++) {
        ++cnt[N[i] - '0'];
        sum_digits += N[i] - '0';
    }
    if (sum_digits % 3 || !cnt[0])
        printf("-1");
    else
        for (int i = 9; i >= 0; i--)
            while (cnt[i]--)
                printf("%d", i);
}