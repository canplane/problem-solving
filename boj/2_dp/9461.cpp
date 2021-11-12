#include <iostream>
using namespace std;

long long P[101] = { 0, 1, 1, 1, 2, 2, };

int main() {
    for (int i = 6; i <= 100; i++) {
        P[i] = P[i - 1] + P[i - 5];
    }
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << P[N] << endl;
    }
}