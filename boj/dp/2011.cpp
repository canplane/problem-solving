#include <iostream>
#define n(i) (s[i] - '0')

using namespace std;

char s[5001];
int m[5000];

int main()
{
    int i, tmp;

    cin >> s;
    for (i = 0; s[i]; i++) {
        if (i && 9 < (tmp = 10 * n(i - 1) + n(i)) && tmp < 27)
            m[i] = (m[i] + (i > 1 ? m[i - 2] : 1)) % 1000000;
        if (n(i))
            m[i] = (m[i] + (i > 0 ? m[i - 1] : 1)) % 1000000;
    }
    cout << m[i - 1];
}