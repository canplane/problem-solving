#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    int N;
    string s;
    cin >> s;
    cin >> N;

    list<char> l(s.begin(), s.end());

    auto now = l.end();
    while (N--) {
        char c;
        cin >> c;
        switch (c) {
        case 'L':
            if (now != l.begin())
                now--;
            break;
        case 'D':
            if (now != l.end())
                now++;
            break;
        case 'B':
            if (now != l.begin())
                now = l.erase(--now);
            break;
        case 'P':
            cin >> c;
            l.insert(now, c);
            break;
        }
    }
    for (auto &c : l) cout << c;
}