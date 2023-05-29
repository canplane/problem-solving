#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N, x;
    std::string s;
    vector<int> v;

    cin >> N;
    while (N--) {
        cin >> s;
        if (s == "push")
            cin >> x, v.push_back(x);
        else if (s == "pop") {
            if (v.empty())
                cout << -1 << "\n";
            else
                cout << v.back() << "\n", v.pop_back();
        } else if (s == "size")
            cout << v.size() << "\n";
        else if (s == "empty")
            cout << v.empty() << "\n";
        else
            cout << (v.size() ? v.back() : -1) << "\n";
    }
}