#include <iostream>
#include <string>

using namespace std;

long long atoll(const string& s) {
    long long d = 0;
    for (int i = 0; i < s.size(); i++)
        d = 10 * d + (s[i] - '0');
    return d;
}

int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << atoll(a + b) + atoll(c + d);
}