#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string s_tolower(string s)
{
    string t = s;
    for (char &c : t)   c = tolower(c);
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int N;
        cin >> N;
        if (!N)     break;

        string min = string(20, 'z');
        while (N--) {
            string s;
            cin >> s;
            if (s_tolower(s) < s_tolower(min))
                min = s;
        }
        cout << min << endl;
    }
}