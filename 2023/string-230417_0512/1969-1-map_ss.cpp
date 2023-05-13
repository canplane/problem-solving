#include <iostream>
#include <sstream>
#include <map>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    map<char, int> cnt[M];
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
            cnt[j][s[j]]++;
    }

    stringstream ss;
    int dist = 0;
    for (int j = 0; j < M; j++) {
        char c = 'A';
        for (auto e : cnt[j]) {
            if (cnt[j][e.first] > cnt[j][c])
                c = e.first;
        }
        ss << c;

        for (auto e : cnt[j]) {
            if (e.first != c)
                dist += e.second;
        }
    }
    cout << ss.str() << endl << dist;
}