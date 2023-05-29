#include <iostream>
using namespace std;

int A[1000], asc[1000], desc[1000], maxlen;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] < A[i])
                asc[i] = max(asc[i], asc[j]);
        }
        asc[i]++;
    }
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j])
                desc[i] = max(desc[i], desc[j]);
        }
        desc[i]++;
    }

    for (int i = 0; i < N; i++) {
        maxlen = max(maxlen, asc[i] + desc[i] - 1);
    }
    cout << maxlen;

}