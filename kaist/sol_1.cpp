#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for (auto s : completion)
        m[s]++;
    
    for (auto s : participant) {
        if (m[s] == 0) {
            answer = s;
            break;
        }
        m[s]--;
    }

    return answer;
}