#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string s, rs;

int main()
{
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //

    getline(cin, s);
    rs = s;
    reverse(rs.begin(), rs.end());
    int len = s.length();

    int ret;
    for (int i = 0; i < len; i++) {
        bool match = true;
        for (int j = i; j < len; j++) {
            if (s[j] != rs[j - i]) {
                match = false;
                break;
            }
        }
        if (match) {
            ret = len + i;
            break;
        }
    }
    
    cout << ret;
}