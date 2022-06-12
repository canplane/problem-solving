#include <iostream>
using namespace std;

int main()
{
    int N, i, j;
    cin >> N;
    for (i = 1; i <= 2 * N - 1; i++) {
        for (j = 1; j <= (N - 1) - abs(N - i); j++)
            cout << " ";
        for (j = 1; j <= 2 * abs(N - i) + 1; j++)
            cout << "*";
        cout << endl;
    }
}