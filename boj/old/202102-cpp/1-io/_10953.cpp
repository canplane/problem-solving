#include <iostream>
#include <string>

int main()
{
    int t;
    std::string s;

    std::cin >> t;
    while (t--) {
        std::cin >> s;
        std::cout << (s[0] - '0') + (s[2] - '0') << std::endl;
    }
}