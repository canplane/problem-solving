// map으로 할 때는 단순히 키를 조회할 때도 공간이 추가되므로 size에 있어 주의해야 함

using namespace std;
#include <iostream>
#include <set>

set<string> dic;

int main()
{
    dic.insert("ChongChong");

    int N;
    cin >> N;
    while (N--) {
        string s, t;
        cin >> s >> t;
        if (dic.find(s) != dic.end() || dic.find(t) != dic.end()) {
            dic.insert(s), dic.insert(t);
        }
    }
    cout << dic.size();
}