#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N, x;
    string s;
    queue<int> q;
    cin >> N;
    while (N--) {
        cin >> s;
        if (s == "push")
            cin >> x, q.push(x);
        else if (s == "pop") {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << endl, q.pop();
        } else if (s == "size")
            cout << q.size() << "\n";
        else if (s == "empty")
            cout << q.empty() << "\n";
        else if (s == "front")
            cout << (q.empty() ? -1 : q.front()) << "\n";
        else
            cout << (q.empty() ? -1 : q.back()) << "\n";
    }
}