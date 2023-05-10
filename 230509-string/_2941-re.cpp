/*
#include <regex>
S = regex_replace(S, regex(PATTERN), REPL)
*/

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    string s;
    cin >> s;
    s = regex_replace(s, regex("c=|c-|dz=|d-|lj|nj|s=|z="), "0");
    cout << s.length();
}