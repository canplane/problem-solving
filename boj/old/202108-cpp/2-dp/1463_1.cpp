#include <iostream>
#include <algorithm>
using namespace std;

long long f(int n) {
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    
    return min(f(n / 2) + n % 2, f(n / 3) + n % 3) + 1;
}

int main() {
    int N;

    cin >> N;
    cout << f(N);
}