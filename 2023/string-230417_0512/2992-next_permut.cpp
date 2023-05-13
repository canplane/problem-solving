#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string X;

int main()
{
    cin >> X;
    cout << (next_permutation(X.begin(), X.end()) ? stoi(X) : 0);   // next_permutation이 알아서 중복 빼주고 다음 오름차순 해준다.
}