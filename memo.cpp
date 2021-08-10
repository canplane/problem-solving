#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    bool included;
    for (int i = 0; i < participant.size(); i++)
    {
        included = false;
        for (int j = 0; j < completion.size(); j++)
        {
            if (participant[i] == completion[j])
            {
                included = true;
                answer = participant[i];
                break;
            }
        }
        if (!included)
            break;
    }

    return answer;
}