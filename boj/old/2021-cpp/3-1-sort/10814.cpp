#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#define MAX_N 100000

using namespace std;

struct Member {
    int age; 
    string name;
    bool operator<(const Member& m) const { return age < m.age; }
} members[MAX_N];

int main()
{
    int N, i;
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> members[i].age >> members[i].name;
    stable_sort(members, members + N);
    for (i = 0; i < N; i++)
        cout << members[i].age << " " << members[i].name << "\n";
}