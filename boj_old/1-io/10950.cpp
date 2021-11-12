#include <iostream>

int main()
{
    int t;
    int a, b;

    std::cin >> t;
    while (t--) {
        std::cin >> a >> b;
        std::cout << (a + b) << std::endl;
    }
}