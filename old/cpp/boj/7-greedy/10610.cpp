#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

char N[100001];
int len = 0;

int main() {
    char c;
    while (scanf("%c", &c) != -1 && isdigit(c))
        N[len++] = c;
    
    int sum_of_digits = 0;
    bool has_zero = false;
    for (int i = 0; i < len; i++) {
        if (N[i] == '0')
            has_zero = true;
        sum_of_digits += N[i] - '0';
    }
    
    if (sum_of_digits % 3 || !has_zero)
        printf("-1");
    else {
        sort(N, N + len, greater<>());
        for (int i = 0; i < len; i++)
            printf("%c", N[i]);
    }
}