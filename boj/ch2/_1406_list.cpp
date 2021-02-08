#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    string s;
    int N;

    cin >> s;
    list<char> l(s.begin(), s.end());  // 반복자 구간 (s.begin(), s.end())으로 초기화된 원소를 갖는다.
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
            if (now != l.begin()) now = l.erase(--now);  // bidirectional iterator니까 --, ++만 가능
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