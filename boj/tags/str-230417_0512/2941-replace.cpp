#include <string>
#include <iostream>
using namespace std;

string patterns[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main()
{
    string s;
    cin >> s;
    for (string pattern : patterns) {
        int pos = -1;
        while ((pos = s.find(pattern, pos + 1)) != string::npos)    //
            s.replace(pos, pattern.length(), " ");                  //
        //cout << pattern << " " << s << endl;
    }
    cout << s.length();
}