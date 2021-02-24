#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, i;
    cin >> N;
    vector<int> v(N);
    for (i = 0; i < N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (i = 0; i < N; i++)
        cout << v[i] << endl;  // cin/cout은 printf/scanf에 비해 느리고, endl은 "\n"에 비해 더 느리다.
}