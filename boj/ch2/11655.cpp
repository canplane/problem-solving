#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string s;
    getline(std::cin, s);
    for (auto& c : s) {
        if (islower(c)) c = 'a' + ((c - 'a') + 13) % 26;
        else if (isupper(c) ) c = 'A' + ((c - 'A') + 13) % 26;
    }
    std::cout << s;
}