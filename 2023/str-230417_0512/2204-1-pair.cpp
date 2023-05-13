#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int N;
        cin >> N;
        if (!N)     break;
        
        vector<pair<string, string>> v(N);
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;

            stringstream ss;
            for (char c : s)
                ss << string(1, c < 'a' ? c + 32 : c);
            v[i] = make_pair(ss.str(), s);
        }

        sort(v.begin(), v.end());

        cout << v[0].second << endl;
    }
}