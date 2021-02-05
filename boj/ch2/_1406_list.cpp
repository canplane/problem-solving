#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    string s;
    int N;

    cin >> s;
    list<char> l(s.begin(), s.end());
    auto now = l.end();

    cin >> N;
    while (N--) {
        char tmp;
        cin >> tmp;

        switch (tmp) {
        case 'L':
            if (now != l.begin()) now--;
            break;
        case 'D':
            if (now != l.end()) now++;
            break;
        case 'B':
            if (now != l.begin()) now = l.erase(--now);  //
            break;
        case 'P':
            cin >> tmp;
            l.insert(now, tmp);
            break;
        }
    }
    
    for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }
}