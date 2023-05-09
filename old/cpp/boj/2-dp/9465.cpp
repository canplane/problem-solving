#include <iostream>
#define MAX_N 100000

using namespace std;

int tbl[2][MAX_N];

int main()
{
    int T;
    int n, row, col, tmp;

    cin >> T;
    while (T--) {
        cin >> n;
        for (row = 0; row < 2; row++)
            for (col = 0; col < n; col++)
                cin >> tbl[row][col];

        for (col = 0; col < n; col++) {
            if (col > 1) {
                tmp = max(tbl[0][col - 2], tbl[1][col - 2]);
                tbl[0][col] += max(tbl[1][col - 1], tmp);
                tbl[1][col] += max(tbl[0][col - 1], tmp);
            } else {
                tbl[0][col] += tbl[1][col - 1];
                tbl[1][col] += tbl[0][col - 1]; 
            }
        }
        cout << max(tbl[0][n - 1], tbl[1][n - 1]) << endl;
    }
}