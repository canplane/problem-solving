#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    int N, x;
    deque<int> deq;
    string s;
    cin >> N;
    while (N--) {
        cin >> s;
        if (s == "push_front") {
            cin >> x;
            deq.push_front(x);
        }
        else if (s == "push_back") {
            cin >> x;
            deq.push_back(x);
        }
        else if (s == "pop_front") {
            if (deq.empty())
                cout << "-1\n";
            else
                cout << deq.front() << "\n", deq.pop_front();
        }
        else if (s == "pop_back") {
            if (deq.empty())
                cout << "-1\n";
            else
                cout << deq.back() << "\n", deq.pop_back();
        }
        else if (s == "size") {
            cout << deq.size() << "\n";
        }
        else if (s == "empty") {
            cout << deq.empty() << "\n";
        }
        else if (s == "front") {
            cout << (deq.empty() ? -1 : deq.front()) << "\n";
        }
        else {
            cout << (deq.empty() ? -1 : deq.back()) << "\n";
        }
    }
}