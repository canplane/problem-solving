#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>  // pair
using namespace std;

string d[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", };

string conv(int n)
{
    string s = to_string(n);
    string ret = "";
    for (int i = 0; i < s.length(); i++)
        ret += d[s[i] - '0'] + " ";
    ret.erase(ret.length() - 1);
    return ret;
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);

    vector<pair<string, int>> v;
    for (int i = M; i <= N; i++)
        v.push_back(make_pair(conv(i), i));
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        printf("%d ", get<1>(v[i]));
        if (i % 10 == 9)
            puts("");
    }
}