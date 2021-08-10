#include <iostream>
#include <cstdio>
using namespace std;

#include "sol.cpp"

//!--

#include <vector>
#include <string>

//

int main() {
    //!--
    
    vector<string> participant = { "mislav", "stanko", "mislav", "ana" };
    vector<string> completion = { "stanko", "ana", "mislav" };
    cout << solution(participant, completion) << endl;
    
    //
}